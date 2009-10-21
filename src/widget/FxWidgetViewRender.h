/*
 * FxWidgetViewRender.h
 *
 *  Created on: 2009-9-3
 *      Author: veiz
 */

/*
 * Javascript wrapper for web frame rendering.
 *
 * */
#ifndef FXWIDGETVIEWRENDER_H_
#define FXWIDGETVIEWRENDER_H_

#include <QWebFrame>
#include "FxContact.h"

#include "fxdebug.h"

class FxWidgetViewRender : public QObject{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
    public:
        FxWidgetViewRender(QWebFrame*);
        virtual ~FxWidgetViewRender();

    public:
        void init(QList<FxContact *> *);
        void addGroupNode(quint32, QString, QString);
        void addContactNode(quint32, quint32, QString, QString, QString, QString);

    private:
        QWebFrame* frame;
        QList<quint32> listGid;
        QList<quint32> listUid;
};

#endif /* FXWIDGETVIEWRENDER_H_ */
