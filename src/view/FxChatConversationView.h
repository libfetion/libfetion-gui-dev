#ifndef FXCHATCONVERSATIONVIEW_H
#define FXCHATCONVERSATIONVIEW_H

#include <QtGui/QWidget>
#include "fxdebug.h"

namespace Ui {
    class FxChatConversationView;
}

class FxChatConversationView : public QWidget {
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
    public:
        FxChatConversationView(QWidget *parent = 0);
        ~FxChatConversationView();

    protected:
        void changeEvent(QEvent *e);

    private:
        Ui::FxChatConversationView *m_ui;
};

#endif // FXCHATCONVERSATIONVIEW_H
