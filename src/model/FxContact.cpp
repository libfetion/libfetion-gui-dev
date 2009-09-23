/*
 * FxContact.cpp
 *
 *  Created on: 2009-9-3
 *      Author: veiz
 */

#include "FxContact.h"

FxContact::FxContact()
{
    // TODO Auto-generated constructor stub

}

FxContact::~FxContact()
{
    // TODO Auto-generated destructor stub
}

QString
FxContact::getMobileNr() const
{
    return mobileNr;
};

void
FxContact::setMobileNr(const QString & p)
{
    mobileNr = p;
}

QString
FxContact::getFetionNr() const
{
    return fetionNr;
}

void
FxContact::setFetionNr(const QString & p)
{
    fetionNr = p;
}
QString
FxContact::getNick() const
{
    return nick;
}
void
FxContact::setNick(const QString & p)
{
    nick = p;
}
QString
FxContact::getName() const
{
    return name;
}
void
FxContact::setName(const QString & p)
{
    name = p;
}
QString
FxContact::getGender() const
{
    return gender;
}
void
FxContact::setGender(const QString & p)
{
    gender = p;
}
QString
FxContact::getScore() const
{
    return score;
}
void
FxContact::setScore(const QString & p)
{
    score = p;
}
QString
FxContact::getImpresa() const
{
    return impresa;
}
void
FxContact::setImpresa(const QString & p)
{
    impresa = p;
}
QString
FxContact::getState() const
{
    return state;
}
void
FxContact::setState(const QString & p)
{
    state = p;
}
QString
FxContact::getCity() const
{
    return city;
}
void
FxContact::setCity(const QString & p)
{
    city = p;
}

int
FxContact::getGroupNr()
{
    return groupNr;
}
void
FxContact::setGroupNr(int p)
{
    groupNr = p;
}
int
FxContact::getOnlineStatus()
{
    return online;
}
void
FxContact::setOnlineStatus(int p)
{
    online = p;
}
