/*
 * FxChannel.h
 *
 *  Created on: 2009-9-3
 *      Author: veiz
 */

#ifndef FXCHANNEL_H_
#define FXCHANNEL_H_

#include <QObject>

#include "FxContact.h"
#include "FxMessage.h"

class FxChannel:public QObject
{
    Q_OBJECT
    public:
        FxChannel();
        virtual ~FxChannel();

    private:
        bool    isGroupChat();
        FxChannel  *channelSetup();
        QList<FxChannel *> retrieveGroupMemberList();
        FxMessage  *recvMessage();
        bool   *sentMessage();

    private:
        /* recipient */
        FxContact  *contact;
        FxMessage  *message;
        bool        delay;
        /*TODO: send times */
        quint32     times;
        /* need encrpt transfer the messages */
        bool        secure;
        /* remote_name + local_name */
        QString     group_id;

};

#endif /* FXCHANNEL_H_ */
