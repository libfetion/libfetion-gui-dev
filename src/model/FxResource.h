/*
 * FxResource.h
 *
 *  Created on: 2009-9-6
 *      Author: veiz
 */

#ifndef FXRESOURCE_H_
#define FXRESOURCE_H_

#include <QObject>
#include <QDomDocument>
#include <QPixmap>

#include <QDir>

#include "fxdebug.h"
typedef enum
{
    MSG_SOUND = 0, ONLINE_SOUND, SYS_SOUND
} SOUND_TYPE;

//here will using enmu replace
#define IMBuddyIcon         1
#define SMSBuddyIcon        2
#define GetInfoBuddyIcon    3
#define ReNameBuddyIcon     4
#define DeleteBuddyIcon     5
#define BackInBuddyIcon     6
#define AddBuddyIcon        7
#define SetImpresaIcon      8
#define AddGroupIcon        9
#define AboutIcon           10
#define ExitIcon            11
#define ApplyIcon           12
#define CancelIcon          13
#define MoveIcon            14
#define RefreshBuddyIcon    15
#define RemoveBlackIcon     16
#define OptionsIcon         17
#define HistoryIcon         18
#define SkinIcon            19

#define ReNameGroupIcon ReNameBuddyIcon
#define DeleteGroupIcon DeleteBuddyIcon

class FxResource : public QObject
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
    public:
        FxResource();
        virtual ~FxResource();
    public:
        QString getXMLRes(QString, QString);
        void setXMLRes(QDomDocument *xml);
        QString dataResPath() { return home() + "/.libfetion"; };
        QString configFile() { return dataResPath() + "/" + FX_CONFIG_FILE; };
        QString defaultResPath();
        QString getSkinPath() { return defaultResPath() + "/skins"; };
        QString defaultSkinPath() { return getSkinPath() + "/default"; };
        QString defaultSoundPath() { return defaultResPath() + "/sound"; };
        QString defaultDataPath() { return defaultResPath() + "/data"; };
        QString home() { return QDir::homePath(); };
        QString FxFacePath();
        void playSound(SOUND_TYPE type);
        void execPlaySound(QString file);

        QPixmap getOnlineStatusIcon(int online_status);
        QPixmap getSysTrayIcon(int status);
        QPixmap getMenuIcon(int menuID);
        QPixmap getQunIcon();
        QPixmap getBT_SMSIcon();

        QPixmap getInputFaceIcon(); //this function is get the inputFace dialog is background picture
        QPixmap getFaceIcon(); //this function is get the face toolbutton is picture
        QPixmap getSendIcon(); //this function is get the send toolbutton is picture
        QPixmap getNudgeIcon(); //this function is get the nudge toolbutton is picture
        QPixmap getHistoryIcon(); //this function is get the history toolbutton is picture
        QPixmap getChangeSendModIcon(); //this function is get the change_send_mod toolbutton is picture

        QPixmap getFlickIcon(bool flag);

        QPixmap getLoginImage(); //this function is get the login picture
        QPixmap getPortraitImage(); //this function is get the portrait picture
        QPixmap getImpresaBKImage(); //this function is get the mood background picture
        QPixmap getSearchBKImage(); //this function is get the Search background picture
        QPixmap getAddImage(); //this function is get the add picture

        QPixmap getBTSettingImage(); //this function is get the setting button's picture
        QPixmap getBTSendSelfImage(); //this function is get the send self button's picture


        QPixmap getLibFetionImage();
        QPixmap getLogion_InImage();
        QPixmap getLogin_CancelImage();

        QPixmap getCloseTabImage(); //this function is get the close tab picture
    private:
        QDomDocument *ResXML;
        static const QString FX_CONFIG_FILE;
        static const QString FX_DATABASE_NAME;
        static const QString FX_SKIN_CONFIG;
        static const quint32 FX_USE_SERVER_TIME;

};
#endif /* FXRESOURCE_H_ */
