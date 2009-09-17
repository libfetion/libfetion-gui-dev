#ifndef FXLOGINWINDOW_H
#define FXLOGINWINDOW_H

#include <QtGui/QWidget>

#include "fxdebug.h"

namespace Ui {
    class FxLoginWindow;
}

class FxLoginWindow : public QWidget {
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER

    public:
        FxLoginWindow(QWidget *parent = 0);
        ~FxLoginWindow();

    protected:
        void changeEvent(QEvent *e);

    signals:
        /* notify "login-started" */
        void SignalLoginStarted();
        /* notify "login-terminated" */
        void SignalLoginTerminated();

    private slots:
        void handleLoginOTG(int);
        void slotLoginClicked();
        void slotPresenceChanged();
        void slotAutoLoginEnabled();
        void slotStorePasswdEnabled();

    private:
        void enableLoginBtn();
        void disableLoginBtn();
        void updateLoginStatusText(QString);

    public:
        QString     id;
        QString     passwd;
        QString     presence;

    private:
        bool        m_loginState;
    private:
        Ui::FxLoginWindow *m_ui;
};

#endif // FXLOGINWINDOW_H
