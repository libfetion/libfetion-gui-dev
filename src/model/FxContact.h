/*
 * FxContact.h
 *
 *  Created on: 2009-9-3
 *      Author: veiz
 */

#ifndef FXCONTACT_H_
#define FXCONTACT_H_

#include <QObject>

class FxContact:public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString mobileNr READ getMobileNr WRITE setMobileNr)
    Q_PROPERTY(QString fetionNr READ getFetionNr WRITE setFetionNr)
    Q_PROPERTY(QString nick READ getNick WRITE setNick)
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QString gender READ getGender WRITE setGender)
    Q_PROPERTY(QString score READ getScore WRITE setScore)
    Q_PROPERTY(QString impresa READ getImpresa WRITE setImpresa)
    Q_PROPERTY(QString state READ getState WRITE setState)
    Q_PROPERTY(QString city READ getCity WRITE setCity)
    Q_PROPERTY(int groupNr READ getGroupNr WRITE setGroupNr)
    Q_PROPERTY(int online READ getOnlineStatus WRITE setOnlineStatus)

    public:
        FxContact();
        virtual ~FxContact();

        QString getMobileNr() const;
        void setMobileNr(const QString &);

        QString getFetionNr() const;
        void setFetionNr(const QString &);

        QString getNick() const;
        void setNick(const QString &);

        QString getName() const;
        void setName(const QString &);

        QString getGender() const;
        void setGender(const QString &);

        QString getScore() const;
        void setScore(const QString &);

        QString getImpresa() const;
        void setImpresa(const QString &);

        QString getState() const;
        void setState(const QString &);

        QString getCity() const;
        void setCity(const QString &);

        int getGroupNr();
        void setGroupNr(int);

        int getOnlineStatus();
        void setOnlineStatus(int);

    private:
        QString mobileNr;
        QString fetionNr;
        QString nick;
        QString name;
        QString gender;
        QString score;
        QString impresa;
        QString state;
        QString city;
        int     groupNr;
        int     online;

};

#endif /* FXCONTACT_H_ */
