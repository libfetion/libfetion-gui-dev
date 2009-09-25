#ifndef FXCONTACTLISTWIDGET_H
#define FXCONTACTLISTWIDGET_H

#include <QtGui/QWidget>

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

};

#endif // FXCONTACTLISTWIDGET_H
