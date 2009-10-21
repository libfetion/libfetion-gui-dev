#ifndef FXCONTACTLISTWIDGET_H
#define FXCONTACTLISTWIDGET_H

#include <QtGui/QWidget>
#include <QLabel>

#include "FxWidgetViewRender.h"
#include "FxContact.h"

#include "fxdebug.h"

namespace Ui {
    class FxContactListWidget;
}

class FxContactListWidget : public QWidget {
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
    public:
        FxContactListWidget(QWidget *parent = 0);
        ~FxContactListWidget();

    protected:
        void changeEvent(QEvent *e);

    private slots:
        void slotHandleClvUpdate(QList<FxContact *> *);

    private:
        void setupSimpleView();
        void setupComplexView();

    private:
        bool useSimpleView;
        FxWidgetViewRender  *render;
        /* All the contacts with group id specified */
        QList<FxContact *>  *data;

};

#endif // FXCONTACTLISTWIDGET_H
