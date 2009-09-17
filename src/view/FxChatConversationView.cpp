#include "FxChatConversationView.h"
#include "ui_FxChatConversationView.h"

FxChatConversationView::FxChatConversationView(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::FxChatConversationView)
{
    m_ui->setupUi(this);
}

FxChatConversationView::~FxChatConversationView()
{
    delete m_ui;
}

void FxChatConversationView::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
