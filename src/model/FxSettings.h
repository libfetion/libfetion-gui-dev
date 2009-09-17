/*
 * FxSettings.h
 *
 *  Created on: 2009-9-3
 *      Author: veiz
 */

#ifndef FXSETTINGS_H_
#define FXSETTINGS_H_

#include <QObject>
class FxSettings:public QObject
{
    Q_OBJECT
    public:
        FxSettings();
        virtual ~FxSettings();
        static FxSettings *getInstance();

    signals:
        void settingChanged();

    private:
        QString file;
};


#endif /* FXSETTINGS_H_ */
