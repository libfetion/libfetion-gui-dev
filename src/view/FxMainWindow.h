#ifndef FXMAINWINDOW_H
#define FXMAINWINDOW_H

#include <QtGui/QWidget>
#include "FxContact.h"

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

    private slots:
        void slotHandleSelfInfoUpdated(FxContact *);
        void slotHandleContactListUpdated();

    protected:
        void changeEvent(QEvent *e);

    private:
        Ui::FxMainWindow *m_ui;
};

#endif // FXMAINWINDOW_H
