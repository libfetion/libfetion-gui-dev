#include "FxContactListWidget.h"
#include <QLabel>

FxContactListWidget::FxContactListWidget(QWidget *parent) :
    QWidget(parent)
{
    FX_FUNCTION
    QLabel *lbl = new QLabel("FxContactListWidget");
    lbl->show();
}

FxContactListWidget::~FxContactListWidget()
{
    FX_FUNCTION
}

void FxContactListWidget::changeEvent(QEvent *e)
{
    FX_FUNCTION
    QWidget::changeEvent(e);
}
