#include "FxLoginWindow.h"
#include "ui_FxLoginWindow.h"

#include "libfetion.h"

#include "FxStrings.h"

FxLoginWindow::FxLoginWindow(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::FxLoginWindow)
{
    FX_FUNCTION
    m_ui->setupUi(this);

    m_loginState = false;
}

FxLoginWindow::~FxLoginWindow()
{
    delete m_ui;
}

void
FxLoginWindow::changeEvent(QEvent *e)
{
    FX_FUNCTION
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void
FxLoginWindow::handleLoginOTG(int error)
{
    FX_FUNCTION
    switch (error)
    {
        case FX_LOGIN_URI_ERROR:
            updateLoginStatusText(QObject::tr(_fx_login_mobile_nb_error_));
            enableLoginBtn();
            break;
        case FX_LOGIN_CONNECTING:
            updateLoginStatusText(QObject::tr(_fx_login_connecting_server_));
            break;
        case FX_LOGIN_WAIT_AUTH:
            updateLoginStatusText(QObject::tr(_fx_login_wait_server_auth_));
            break;
        case FX_LOGIN_AUTH_OK:
            updateLoginStatusText(QObject::tr(_fx_login_server_auth_ok_));
            break;
        case FX_LOGIN_FAIL:
            updateLoginStatusText(QObject::tr(_fx_login_error_password_));
            enableLoginBtn();
            break;
        case FX_LOGIN_NETWORK_ERROR:
            updateLoginStatusText(QObject::tr(_fx_login_error_network_));
            enableLoginBtn();
            break;
        case FX_LOGIN_UNKOWN_ERROR:
            updateLoginStatusText(QObject::tr(_fx_login_error_unknown_));
            enableLoginBtn();
            break;
        case FX_LOGIN_TIMEOUT:
            updateLoginStatusText(QObject::tr(_fx_login_time_out_));
            enableLoginBtn();
            break;
        case FX_LOGIN_UNKOWN_USR:
            updateLoginStatusText(QObject::tr(_fx_login_unknown_uid_));
            enableLoginBtn();
            break;
        case FX_LOGIN_GCL_FAIL:
            updateLoginStatusText(QObject::tr(_fx_login_get_contact_list_fail_));
            enableLoginBtn();
            break;
        case FX_LOGIN_GP_FAIL:
            updateLoginStatusText(QObject::tr(_fx_login_get_contact_info_fail_));
            enableLoginBtn();
            break;
        case FX_LOGIN_OK:
            updateLoginStatusText(QObject::tr(_fx_login_ok_));
            break;
        case FX_LOGIN_GCL_GETTING:
        case FX_LOGIN_GCL_OK:
        case FX_LOGIN_GP_GETTING:
        case FX_LOGIN_GP_OK:
        default:
            /* unkown error code */
            break;
    }
}
void
FxLoginWindow::enableLoginBtn()
{
    FX_FUNCTION
    m_ui->btnLogin->setEnabled(true);
    m_loginState = true;

}
void
FxLoginWindow::disableLoginBtn()
{
    FX_FUNCTION
    m_ui->btnLogin->setEnabled(false);
    m_loginState = false;
}
void
FxLoginWindow::updateLoginStatusText(QString text)
{
    FX_FUNCTION
    m_ui->textLoginStatus->setText(text);
}

/* private slots */
void
FxLoginWindow::slotLoginClicked()
{
    FX_FUNCTION
    if (m_loginState)
    {
        m_loginState = false;
        emit SignalLoginTerminated();
    }else
    {
//        id = m_ui->inputFetionId->text();
//        passwd = m_ui->inputFetionPasswd->text();
        id = "15828088095";
        passwd = "111//sigh";
        presence = m_ui->textLoginStatus->text();
        m_loginState = true;

        emit SignalLoginStarted();
    }
}
void
FxLoginWindow::slotPresenceChanged()
{
    FX_FUNCTION
}
void
FxLoginWindow::slotAutoLoginEnabled()
{
    FX_FUNCTION
}
void
FxLoginWindow::slotStorePasswdEnabled()
{
    FX_FUNCTION
}
