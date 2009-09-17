/*
 * FxSession.cpp
 *
 *  Created on: 2009-9-3
 *      Author: veiz
 */


#include "FxSession.h"

#include "fxdebug.h"

#include "FxInstance.h"

FxSession *globalSession;

FxSession::FxSession()
{
    FX_FUNCTION
    globalSession = this;

    mapper = new QSignalMapper(this);
}

FxSession::~FxSession()
{
    // TODO Auto-generated destructor stub
}

void
wrapper(int message, WPARAM wParam, LPARAM lParam, void *args)
{
    globalSession->fetionLibEventCallback(message, wParam, lParam, args);
}

/*
 * Login to fetion server
 *     id - user fetion id or mobile number
 * passwd - user password
 * status - status after login, available as
 *          : offline
 *          : busy
 *          : away
 *          : online
 * */
void
FxSession::login(QString id, QString passwd, QString status)
{
#ifdef FX_GUI_DEBUG_ENABLE
    return true;
#else
    if (status == tr("offline"))
    {
        fx_set_login_status(FX_STATUS_OFFLINE);
    }else if (status == tr("busy"))
    {
        fx_set_login_status(FX_STATUS_BUSY);
    }else if (status == tr("away"))
    {
        fx_set_login_status(FX_STATUS_AWAY);
    }
    else
    {
        fx_set_login_status(FX_STATUS_ONLINE);
    }

    QByteArray ba = id.toLatin1();
    const char* uid = ba.data();
    ba = passwd.toLatin1();
    const char* upasswd = ba.data();

    /*TODO: update fx_login after libevent supported */
    fx_login(uid, upasswd, wrapper, this);
#endif
}

void
FxSession::cancel()
{
    FX_FUNCTION
    fx_cancel_login();
}

void
FxSession::leave()
{
    // TODO should support temporary leave?
}

void
FxSession::quit()
{
    FX_FUNCTION
#ifdef FX_GUI_DEBUG_ENABLE
#else
    // TODO do real logout here
    fx_loginout();
#endif
}

//add account to it's group item
void FxSession::addAccountToGroup(const Fetion_Account *account)
{
    //remove the user's id on account from list...
    if (!account || account->id == (qlonglong)strtol(fx_get_usr_uid(), NULL, 10)
        )
    {
        return ;
    }

    int group_no = fx_get_account_group_id(account);
    if (group_no <= 0)
    {
        create_zero_group();
    }

    char *showname = fx_get_account_show_name(account, TRUE);
    QString show_name = QString::fromUtf8(showname);
    int online_state = fx_get_online_status_by_account(account);

    addAccountToGroup(account, show_name, online_state, group_no);

    if (showname)
    {
        free(showname);
    }
}

void
FxSession::retrieveContactList()
{
    FX_FUNCTION

    const Fetion_Account *contact = fx_get_first_account();
    while (contact)
    {
        addAccountToGroup(contact);
        contact = fx_get_next_account(contact);
    }

    emit SignalContactListUpdated();
}

void
FxSession::updateSelfInfo()
{
    FX_FUNCTION
    self = new FxContact();

    const Fetion_Personal *p = fx_data_get_PersonalInfo();

    QString mnr(p->mobile_no);
//    QString fnr(p->fetion_no);
    QString nick(p->nickname);
    QString name(p->name);
    QString gender(p->gender);
    QString score(fx_get_usr_score());
    QString impresa(p->impresa);
    QString state(p->province);
    QString city(p->city);

    FX_DEBUG(mnr);
    FX_DEBUG(nick);
    FX_DEBUG(name);
    FX_DEBUG(gender);
    FX_DEBUG(score);
    FX_DEBUG(impresa);
    FX_DEBUG(state);
    FX_DEBUG(city);

    if (nick.isEmpty() && name.isEmpty())
        nick = name = QString(fx_get_usr_show_name());

    self->setMobileNr(mnr);
//    self->setFetionNr("");
    self->setNick(nick);
    self->setName(name);
    self->setGender(gender);
    self->setScore(score);
    self->setImpresa(impresa);
    self->setState(state);
    self->setCity(city);

    emit SignalSelfInfoUpdated(self);
}

void
FxSession::slotHandleUpdatePresence(int status)
{
    FX_FUNCTION
    switch (status)
    {
        case FX_STATUS_ONLINE:
        case FX_STATUS_OFFLINE:
        case FX_STATUS_BUSY:
        case FX_STATUS_AWAY:
            fx_set_user_state(status, NULL, NULL, NULL);
            break;
        default:
            break;
    }
}

void
FxSession::fetionLibEventCallback(
        int message,
        WPARAM wParam,
        LPARAM lParam,
        void *args)
{
    Q_UNUSED(wParam);
    Q_UNUSED(lParam);

    FX_RETURN_IF_FAILED(args);

    switch (message)
    {
        case FX_LOGIN_URI_ERROR:
            FX_DEBUG("FX_LOGIN_URI_ERROR");
            break;
        case FX_LOGIN_CONNECTING:
            FX_DEBUG("FX_LOGIN_CONNECTING");
            break;
        case FX_LOGIN_WAIT_AUTH:
            FX_DEBUG("FX_LOGIN_WAIT_AUTH");
            break;
        case FX_LOGIN_AUTH_OK:
            FX_DEBUG("FX_LOGIN_WAIT_AUTH");
            break;
        case FX_LOGIN_FAIL:
            FX_DEBUG("FX_LOGIN_FAIL");
            break;
        case FX_LOGIN_NETWORK_ERROR:
            FX_DEBUG("FX_LOGIN_NETWORK_ERROR");
            break;
        case FX_LOGIN_UNKOWN_ERROR:
            FX_DEBUG("FX_LOGIN_UNKOWN_ERROR");
            break;
        case FX_LOGIN_TIMEOUT:
            FX_DEBUG("FX_LOGIN_TIMEOUT");
            break;
        case FX_LOGIN_UNKOWN_USR:
            FX_DEBUG("FX_LOGIN_UNKOWN_USR");
            break;
        case FX_LOGIN_GCL_GETTING:
            FX_DEBUG("FX_LOGIN_GCL_GETTING");
            break;
        case FX_LOGIN_GCL_OK:
            FX_DEBUG("FX_LOGIN_GCL_OK");
            break;
        case FX_LOGIN_GCL_FAIL:
            FX_DEBUG("FX_LOGIN_GCL_FAIL");
            break;
        case FX_LOGIN_GP_GETTING:
            FX_DEBUG("FX_LOGIN_GP_GETTING");
            break;
        case FX_LOGIN_GP_OK:
            FX_DEBUG("FX_LOGIN_GP_OK");
            break;
        case FX_LOGIN_GP_FAIL:
            FX_DEBUG("FX_LOGIN_GP_FAIL");
            break;
        case FX_LOGIN_OK:
            FX_DEBUG("FX_LOGIN_OK");
//            retrieveContactList();
            updateSelfInfo();
            break;
        default:
            /* unkown error code */
            break;
    }
    if (message == FX_LOGIN_OK)
        emit globalSession->SignalLoginSuccess();
    else if (message == FX_LOGIN_FAIL)
        emit globalSession->SignalLoginFailed();
    else
        emit globalSession->SignalLoginOTG(message);
}
