/*
 * FxStyleSheet.h
 *
 *  Created on: 2009-9-3
 *      Author: veiz
 */

#ifndef FXSTYLESHEET_H_
#define FXSTYLESHEET_H_

#include <QObject>
//#include <QFile>

#include "fxdebug.h"
class FxStyleSheet : public QObject
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
    public:
        FxStyleSheet(QString);
        virtual ~FxStyleSheet();

        bool store();
    public:
//        QFile rawFile;
        QString ctx;
};


#endif /* FXSTYLESHEET_H_ */
