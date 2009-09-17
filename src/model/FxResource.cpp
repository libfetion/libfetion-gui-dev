/*
 * FxResource.cpp
 *
 *  Created on: 2009-9-6
 *      Author: veiz
 */

#include <QSound>
#include <QFile>
#include <QDir>
#include <QDebug>

#include "FxResource.h"

#include "libfetion.h"

/* static class member initialize */
const QString FxResource::FX_CONFIG_FILE =  "libfetion.conf";
const QString FxResource::FX_DATABASE_NAME = "libfx.db";
const QString FxResource::FX_SKIN_CONFIG = "/skin.xml";
const quint32 FxResource::FX_USE_SERVER_TIME  =  0;

FxResource::FxResource()
{
    // TODO Auto-generated constructor stub

}

FxResource::~FxResource()
{
    // TODO Auto-generated destructor stub
}

void FxResource::setXMLRes(QDomDocument *xml)
{
    if (ResXML)
    {
        ResXML->clear();
    }
    ResXML = xml;
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QString FxResource::getXMLRes(QString item, QString defValue)
{
    if (!ResXML)
    {
        return "";
    }
    return ResXML->documentElement().attribute(item, defValue);

}

QString FxResource::defaultResPath()
{
    QString defaultResPath = QString("");
    bool init = false;

    if (init)
    {
        return defaultResPath;
    }

    //here we set the CREDITS.txt as an identifying item

    if (QFile::exists("./CREDITS.txt"))
    {
        defaultResPath = ".";
    }
    else
    {
        defaultResPath = "/usr/share/libfetion";
    }

    init = true;
    return defaultResPath;
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QString FxResource::FxFacePath()
{
#ifdef WIN32
return "./faces_image";
#else //linux
static QString path;
static bool init = false;

if (init)
{
    return path;
}

if (QFile::exists("./faces_image/1.gif"))
{
    path = "./faces_image";
}
else
{
    path = "/usr/share/libfetion/faces_image";
}

init = true;
return path;
#endif
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

void FxResource::execPlaySound(QString music)
{
#ifdef Q_OS_MAC //Mac OS X platfrom
QSound::play(music);
#else
#ifdef WIN32 //windows platfrom
QSound::play(music);
#else //linux platfrom
// cjacker(cjacker@gmail.com) implement it on linux of ubuntu
QString cmd;
cmd = "aplay " + music + "&";
system(cmd.toStdString().c_str());
#endif
#endif
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

void FxResource::playSound(SOUND_TYPE type)
{
switch (type)
{
    case MSG_SOUND:
//    execPlaySound(Settings::instance().MsgRingPath());
    break;
    case ONLINE_SOUND:
    execPlaySound(defaultSoundPath() + "/online.wav");
    break;
    case SYS_SOUND:
    execPlaySound(defaultSoundPath() + "/sys.wav");
    break;
}
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getOnlineStatusIcon(int status)
{
#define MOBILE_LOGIN 0x011
switch (status)
{
    /* pc offline */
    case 0:
    case 0+MOBILE_LOGIN:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("online_offline", ""));

    case FX_STATUS_BLACK:
    case FX_STATUS_BLACK + MOBILE_LOGIN:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("online_black", ""));

    /* mobile user */
    case FX_STATUS_MOBILE:
    case FX_STATUS_MOBILE + MOBILE_LOGIN:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("online_mobile", ""));

    /* the account waiting */
    case FX_STATUS_WAITING_AUTH:
    case FX_STATUS_WAITING_AUTH + MOBILE_LOGIN:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("online_waiting", ""));

    /* the account is refuse make friends with you */
    case FX_STATUS_REFUSE:
    case FX_STATUS_REFUSE + MOBILE_LOGIN:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("online_refuse", ""));

    case FX_STATUS_OFFLINE:
    case FX_STATUS_OFFLINE + MOBILE_LOGIN:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("online_offline", ""));

    case FX_STATUS_DINNER:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("online_dinner", ""));

    case FX_STATUS_AWAY:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("online_away", ""));

    case FX_STATUS_ONLINE:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("online_online", ""));

    case FX_STATUS_PHONE:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("online_phone", ""));

    case FX_STATUS_BUSY:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("online_busy", ""));

    case FX_STATUS_MEETING:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("online_meeting", ""));

    case FX_STATUS_EXTENDED_AWAY:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("online_extnded_away", ""));

    case FX_STATUS_NUM_PRIMITIVES:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("online_num_primitives", ""));

    case FX_STATUS_ONLINE + MOBILE_LOGIN:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("online_m_online", ""));

    case FX_STATUS_DINNER + MOBILE_LOGIN:
    case FX_STATUS_AWAY + MOBILE_LOGIN:
    case FX_STATUS_EXTENDED_AWAY + MOBILE_LOGIN:
    case FX_STATUS_NUM_PRIMITIVES + MOBILE_LOGIN:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("online_m_away", ""));

    case FX_STATUS_PHONE + MOBILE_LOGIN:
    case FX_STATUS_MEETING + MOBILE_LOGIN:
    case FX_STATUS_BUSY + MOBILE_LOGIN:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("online_m_busy", ""));
#undef MOBILE_LOGIN
    /* should never reach*/
    default:
    return QPixmap("");
}

return QPixmap(getSkinPath() + "/" + getXMLRes("online_offline", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getSysTrayIcon(int status)
{
switch (status)
{
    /* no login */
    case 0:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("systray_offline",""));
    /* login */
    case 1:
    case FX_STATUS_ONLINE:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("systray_online", ""));

    case FX_STATUS_OFFLINE:
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("systray_hide", ""));

    case FX_STATUS_DINNER:
    case FX_STATUS_AWAY:
    case FX_STATUS_MEETING:
    case FX_STATUS_EXTENDED_AWAY:
    case FX_STATUS_NUM_PRIMITIVES:
    return QPixmap(getSkinPath() + "/" + getXMLRes("systray_away", ""));
}
return QPixmap(getSkinPath() + "/" + getXMLRes("systray_busy", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getMenuIcon(int menuID)
{
switch (menuID)
{
    case IMBuddyIcon:
    //IM
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_im", ""));
    case SMSBuddyIcon:
    //SMS
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_sms", ""));
    case GetInfoBuddyIcon:
    //GetInfo
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_profile", ""));
    case ReNameBuddyIcon:
    //rename
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_edit", ""));
    case AddBuddyIcon:
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_addfriend", "")
    );
    case AboutIcon:
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_about", ""));
    case ExitIcon:
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_exit", ""));
    case ApplyIcon:
    case RemoveBlackIcon:
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_apply", ""));
    case CancelIcon:
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_cancel", ""));
    case SetImpresaIcon:
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_edit", ""));
    case AddGroupIcon:
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_addqun", ""));
    case BackInBuddyIcon:
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_backlist", ""))
    ;
    case DeleteBuddyIcon:
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_delete", ""));
    case MoveIcon:
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_move", ""));
    case RefreshBuddyIcon:
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_refresh", ""));
    case OptionsIcon:
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_options", ""));
    case HistoryIcon:
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_history", ""));
    case SkinIcon:
    return QPixmap(getSkinPath() + "/" + getXMLRes("menu_skin", ""));
}
return QPixmap();
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getQunIcon()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("qun_icon", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getBT_SMSIcon()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("bt_smsicon", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getFlickIcon(bool flag)
{
if (flag)
{
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("systray_online", ""));
}
else
{
    return QPixmap(getSkinPath() + "/" +
            getXMLRes("systray_online_flick",""));
}
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getInputFaceIcon()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("input_face", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getFaceIcon()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("tool_face", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getNudgeIcon()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("nudge_button", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getSendIcon()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("send_button", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getHistoryIcon()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("history", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getChangeSendModIcon()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("change_send_mode", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getCloseTabImage()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("closetab", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getLoginImage()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("login_image", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getPortraitImage()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("portrait", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getBTSettingImage()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("bt_setting", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getBTSendSelfImage()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("bt_sendself", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getAddImage()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("addfriend", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getImpresaBKImage()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("impresabk", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getSearchBKImage()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("search", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getLibFetionImage()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("LibFetion", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getLogion_InImage()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("login_in", ""));
}

/**************************************************************************/
/*                                                                        */
/**************************************************************************/

QPixmap FxResource::getLogin_CancelImage()
{
return QPixmap(getSkinPath() + "/" + getXMLRes("login_cancel", ""));
}

