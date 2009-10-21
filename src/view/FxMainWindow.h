#ifndef FXMAINWINDOW_H
#define FXMAINWINDOW_H

#include <QtGui/QWidget>
#include "FxContact.h"
#include "FxContactListWidget.h"

#include "fxdebug.h"

namespace Ui {
    class FxMainWindow;
}

class FxMainWindow : public QWidget {
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER

    public:
        FxMainWindow(QWidget *parent = 0);
        ~FxMainWindow();

    signals:
        /* notify session "session-update-presence" */
        void SignalSessionUpdatePresence(int);
        void SignalClvNeedUpdate(QList<FxContact *> *);

    private slots:
        void slotHandleSelfInfoUpdated(FxContact *);
        void slotHandleContactListUpdated(QList<FxContact *> *);
        void slotHandleAddContactBtnClicked();
        void slotHandleSendSmsToSelfBtnClicked();
        void slotHandleSettingBtnClicked();

    protected:
        void changeEvent(QEvent *e);
    public:
        void setupContactListView();

    private:
        Ui::FxMainWindow     *m_ui;
        FxContactListWidget  *m_clv;
};

#endif // FXMAINWINDOW_H
