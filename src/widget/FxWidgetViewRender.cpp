/*
 * FxWidgetViewRender.cpp
 *
 *  Created on: 2009-9-3
 *      Author: veiz
 */

#include "FxWidgetViewRender.h"

FxWidgetViewRender::FxWidgetViewRender(QWebFrame* web) {
    frame = web;
}

FxWidgetViewRender::~FxWidgetViewRender() {
}

void
FxWidgetViewRender::init(QList<FxContact *> *data)
{
    FX_FUNCTION
    /* TODO: iterate add group/contact to render buffer */
    QList<FxContact *> list;
    list = *(QList<FxContact *> *)data;
    QListIterator<FxContact *> iter(list);

    FxContact *tnode;

    while((iter.hasNext()) && (tnode = iter.next())){
        if (listGid.indexOf(tnode->getGroupNr()) < 0) {
            /* new group found, add to group list */
            listGid.append(tnode->getGroupNr());
            addGroupNode(tnode->getGroupNr(),
                    /* group name*/,
                    /* number*/);
        }
        addContactNode(tnode->getMobileNr(),
                tnode->getGroupNr(),
                /* contact type */,
                /* contact avatar */,
                tnode->getName(),
                tnode->getImpresa());
    }
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
