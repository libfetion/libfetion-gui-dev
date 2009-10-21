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

FxContact*
FxSession::fillInContactInfo(FxContact * contact, const Fetion_Personal *p)
{
    FX_FUNCTION
    FX_RETURN_WITH_VALUE_IF_FAILED(contact, NULL);
    FX_RETURN_WITH_VALUE_IF_FAILED(p, contact);

    QString mnr = QString::fromUtf8(p->mobile_no);
//    QString fnr(p->fetion_no);
    QString nick = QString::fromUtf8(p->nickname);
    QString name = QString::fromUtf8(p->name);
    QString gender(p->gender);
    QString score(fx_get_usr_score());
    QString impresa = QString::fromUtf8(p->impresa);
    QString state = QString::fromUtf8(p->province);
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

    contact->setMobileNr(mnr);
//    contact->setFetionNr("");
    contact->setNick(nick);
    contact->setName(name);
    contact->setGender(gender);
    contact->setScore(score);
    contact->setImpresa(impresa);
    contact->setState(state);
    contact->setCity(city);

    return contact;

}

FxContact *
FxSession::updateContactInfo(const Fetion_Account *account)
{
    FX_FUNCTION
    FX_RETURN_WITH_VALUE_IF_FAILED(account, NULL);

    FxContact *contact = new FxContact();

    /* exclude self contact */
    if (account->id == (qlonglong)strtol(fx_get_usr_uid(), NULL, 10))
    {
        return NULL;
    }

    /* update specified user information */
    fx_update_account_info_by_id(account->id);

    contact = fillInContactInfo(contact, account->personal);
    if (contact != NULL)
    {
        contact->setGroupNr(fx_get_account_group_id(account));
        contact->setName(QString::fromUtf8(fx_get_account_show_name(account, TRUE)));
        contact->setOnlineStatus(fx_get_online_status_by_account(account));
    }
    return contact;
}

void
FxSession::updateSelfInfo()
{
    FX_FUNCTION
    self = new FxContact();

    const Fetion_Personal *p = fx_data_get_PersonalInfo();


    self = fillInContactInfo(self, p);

    emit SignalSelfInfoUpdated(self);
}

void
FxSession::retrieveContactList()
{
    FX_FUNCTION

    FxContact *c = new FxContact();
    const Fetion_Account *contact = fx_get_first_account();

    while (contact)
    {
        c = updateContactInfo(contact);
        if (c != NULL)
            contactList->append(c);
        contact = fx_get_next_account(contact);
    }

    emit SignalContactListUpdated(contactList);
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
            updateSelfInfo();
            retrieveContactList();
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
