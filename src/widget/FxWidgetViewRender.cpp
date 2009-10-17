/*
 * FxWidgetViewRender.cpp
 *
 *  Created on: 2009-9-3
 *      Author: veiz
 */

#include "FxWidgetViewRender.h"

FxWidgetViewRender::FxWidgetViewRender(QWebFrame* web) {
	// TODO Auto-generated constructor stub
    frame = web;
}

FxWidgetViewRender::~FxWidgetViewRender() {
	// TODO Auto-generated destructor stub
}

void
FxWidgetViewRender::init()
{
    FX_FUNCTION
}
void
FxWidgetViewRender::addGroupNode(
        quint32 gid,
        QString name,
        QString number)
{
    FX_FUNCTION
    QString script = QString("ContactListView_addGroup (%1,%2,%3)").arg(gid).arg(name).arg(number);
    frame->evaluateJavaScript(script);
}

void
FxWidgetViewRender::addContactNode(
        quint32 uid,
        quint32 gid,
        QString type,
        QString avatar,
        QString name,
        QString impresa)
{
    FX_FUNCTION
    QString script =
            QString("ContactListView_addContact (%1,%2,%3,%4,%5,%6)").arg(uid).arg(gid).arg(type).arg(avatar).arg(name).arg(impresa);
    frame->evaluateJavaScript(script);
}
