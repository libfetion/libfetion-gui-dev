/*
 * FxInstance.h
 *
 *  Created on: 2009-9-3
 *      Author: veiz
 */

#ifndef FXINSTANCE_H_
#define FXINSTANCE_H_

#include <QApplication>
#include <QObject>
#include <QSignalMapper>

#include "FxLoginWindow.h"
#include "FxMainWindow.h"
#include "FxSettings.h"
#include "FxResource.h"
#include "FxStyleSheet.h"
#include "FxCodec.h"
#include "FxSession.h"

#include "fxdebug.h"
class FxInstance: public QObject
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
    public:
        FxInstance();
        virtual ~FxInstance();
        static FxSettings *getInstance();

    private slots:
        /* recv "stylesheet-update" signal */
        void updateStyleSheet();
        /* recv "settings-update" signal */
        void updateSettings();
        /* recv session "login-success" signal */
        void handleLoginSuccess();
        /* recv session "login-otg" signal */
        void handleLoginOTG(int);
        /* recv session "login-failed" signal */
        void handleLoginFailed();
        /* recv loginwnd "login-started" signal */
        void slotStartLogin();
        /* recv loginwnd "login-terminated" signal */
        void slotTerminateLogin();

    private:
        void localize();
        void displayMainWindow();

    private:
        QSignalMapper    *mapper;
        FxSession        *session;
        /*TODO: Global settings and style are supported only */
        FxSettings       *settings;
        FxStyleSheet     *stylesheet;
        FxCodec          *codec;
        /*FIXME: multi session will share same mainwindow, in pidgin
         * style */
        FxMainWindow     *mainWnd;
        /* resource handler */
        FxResource       *resource;
        FxLoginWindow    *loginWnd;
};

#endif /* FXINSTANCE_H_ */
