/*
 * FxSession.h
 *
 *  Created on: 2009-9-3
 *      Author: veiz
 */

#ifndef FXSESSION_H_
#define FXSESSION_H_

#include <QObject>
#include <QHash>
#include <QSignalMapper>

#include "FxContact.h"
#include "FxChannel.h"

#include "FxEventLogger.h"
#include "FxChatConversationView.h"

#include "common.h"
#include "libfetion.h"

#include "fxdebug.h"
class FxSession : public QObject
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
    public:
        FxSession();
        virtual ~FxSession();
        void fetionLibEventCallback(int, WPARAM, LPARAM, void *);

    public:
        void login(QString, QString, QString);
        void leave(); //TODO: support leave a while?
        void quit();
        void cancel();

    signals:
        /* notify "login-success" */
        void SignalLoginSuccess();
        /* notify "login-otg" */
        void SignalLoginOTG(int);
        /* notify "login-failed" */
        void SignalLoginFailed();
        /* notify ui "session-contact-updated" */
        void SignalContactListUpdated(QList<FxContact *> *);
        /* notify ui "session-self-updated" */
        void SignalSelfInfoUpdated(FxContact *);
        /* notify "session-leave" */
        void SignalSessionLeave();
        /* notify "session-quit" */
        void SignalSessionQuit();

    private slots:
        /* recv "session-update-presence" */
        void slotHandleUpdatePresence(int);

    private:
        void retrieveContactList();
        void updateSelfInfo();
        FxContact *updateContactInfo(const Fetion_Account *);
        FxContact *fillInContactInfo(FxContact *,
                                     const Fetion_Personal *);

    private:
        /* Self information data */
        FxContact                   *self;
        /*TODO: Slot manager here, QSignalMapper or QxtSlotMapper? */
        QSignalMapper               *mapper;
        /*
         * Multi channel supported in one session
         */
        QHash<quint32, FxChannel *> channelHash;
        /*
         * Contacts of session, don't distinct group and individual
         * contacts
         * */
        QList<FxContact *>          *contactList;
        FxEventLogger               *el;

        /* user id, can be fetion nr, or phone number*/
        QString                     uid;
        FxChatConversationView      *ccv;
};

#endif /* FXSESSION_H_ */
