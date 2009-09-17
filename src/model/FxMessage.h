/*
 * FxMessage.h
 *
 *  Created on: 2009-9-3
 *      Author: veiz
 */

#ifndef FXMESSAGE_H_
#define FXMESSAGE_H_

#include <QObject>

class FxMessage:public QObject
{
    Q_OBJECT
    public:
        FxMessage();
        virtual ~FxMessage();
    private:
        QString encodeMessage();
        QString decodeMessage();
    private:
        /*
         * Identity of each message, format as
         * <8 random upper characters or number>_<msg index in current chat>
         * like, 45EFA3BD_12
         */
        QString token;
        QString remoteUID;
        QString remoteName;
        QString localUID;
        QString localName;
        QString rawContent;
        /*TODO: content can be MIME type */
        QString rawMIMEContent;
        quint32 timestamp;
};


#endif /* FXMESSAGE_H_ */
