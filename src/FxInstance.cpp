/*
 * FxInstance.cpp
 *
 *  Created on: 2009-9-3
 *      Author: veiz
 */

#include <QTranslator>
#include "FxInstance.h"

#include "fxdebug.h"
FxInstance::FxInstance()
{
    FX_FUNCTION
    localize();

    // TODO Auto-generated constructor stub
    // create session manager

    stylesheet = new FxStyleSheet("");

    codec = new FxCodec();

    loginWnd = new FxLoginWindow();
    loginWnd->show();

    connect(loginWnd, SIGNAL(SignalLoginStarted()), this, SLOT(slotStartLogin()));
    connect(loginWnd, SIGNAL(SignalLoginTerminated()), this, SLOT(slotTerminateLogin()));
}

FxInstance::~FxInstance()
{
    FX_FUNCTION
    // TODO Auto-generated destructor stub
    mainWnd->deleteLater();
}

void
FxInstance::slotStartLogin()
{
    FX_FUNCTION
    session = new FxSession();

    mainWnd = new FxMainWindow();

    session->login(loginWnd->id, loginWnd->passwd, loginWnd->presence);

    connect(session, SIGNAL(SignalLoginSuccess()),
            this, SLOT(handleLoginSuccess()));
    connect(session, SIGNAL(SignalLoginFailed()),
            this, SLOT(handleLoginFailed()));
    connect(session, SIGNAL(SignalLoginOTG(int)),
            loginWnd, SLOT(handleLoginOTG(int)));

    connect(session, SIGNAL(SignalSelfInfoUpdated(FxContact *)),
            mainWnd, SLOT(slotHandleSelfInfoUpdated(FxContact *)));
    connect(session, SIGNAL(SignalContactListUpdated()),
            mainWnd, SLOT(slotHandleContactListUpdated()));
}

void
FxInstance::slotTerminateLogin()
{
    FX_FUNCTION
    session->cancel();

    delete session;
}

void
FxInstance::localize()
{
    FX_FUNCTION
    QString res;

    resource = new FxResource();
    res = resource->defaultResPath();

    if(!res.isEmpty())
    {
        QTranslator translator_fetion;
        translator_fetion.load("fetion_utf8_CN", res);
        QTranslator translator_qt;
        translator_qt.load("qt_zh_CN", res);
        qApp->installTranslator(&translator_fetion);
        qApp->installTranslator(&translator_qt);
    }else
    {
        FX_WARN("Loading localization resource failed, running under en_US env");
    }
}

void
FxInstance::displayMainWindow()
{
    FX_FUNCTION

    mainWnd->setStyleSheet(stylesheet->ctx);
    mainWnd->setupContactListView();
    mainWnd->show();
}

void
FxInstance::updateStyleSheet()
{
    FX_FUNCTION
    // TODO update all widgets' style
    if (mainWnd){
        mainWnd->setStyleSheet(stylesheet->ctx);
    }
}

void
FxInstance::updateSettings()
{
    FX_FUNCTION
}

void
FxInstance::handleLoginSuccess()
{
    FX_FUNCTION
    FX_DEBUG("Login status - success");

    /*TODO: animation for smooth transition */
    loginWnd->deleteLater();
    displayMainWindow();
    connect(mainWnd, SIGNAL(SignalSessionUpdatePresence(int)),
            session, SLOT(slotHandleUpdatePresence(int)));
}

void
FxInstance::handleLoginFailed()
{
    FX_FUNCTION
    FX_DEBUG("Login status - failed");
}

void
FxInstance::handleLoginOTG(int)
{
    FX_FUNCTION
}
