#include "FxMainWindow.h"
#include "ui_FxMainWindow.h"

FxMainWindow::FxMainWindow(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::FxMainWindow)
{
    m_ui->setupUi(this);
}

FxMainWindow::~FxMainWindow()
{
    delete m_ui;
}

void FxMainWindow::changeEvent(QEvent *e)
{
    FX_FUNCTION
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void
FxMainWindow::slotHandleSelfInfoUpdated(FxContact *self)
{
    FX_FUNCTION
    FX_RETURN_IF_FAILED(self);

    FX_DEBUG(self->getNick());
    FX_DEBUG(self->getImpresa());
    
    QString name = self->getNick();
    if (name.isEmpty())
        name = self->getName();
    
    m_ui->textImpresa->insert(self->getImpresa());
    m_ui->textNickname->insert(name);
    repaint();
}

void
FxMainWindow::slotHandleContactListUpdated()
{
    FX_FUNCTION
}
