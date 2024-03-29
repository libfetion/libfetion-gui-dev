#include "FxContactListWidget.h"
#include <QWebView>
#include <QWebFrame>
#include <QUrl>

FxContactListWidget::FxContactListWidget(QWidget *parent) :
    QWidget(parent)
{
    FX_FUNCTION
    /*TODO: pass-in useSimpleView */
    useSimpleView = true;

    if (useSimpleView)
    {
        setupSimpleView();
    }else
    {
        setupComplexView();
    }

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

void
FxContactListWidget::setupSimpleView()
{
    FX_FUNCTION
    QWebView *view = new QWebView(this);
    QWebFrame *frame;
    view->load(QUrl("http://sodu.org/"));
    view->show();
    frame = view->page()->mainFrame();
    render = new FxWidgetViewRender(frame);
    //TODO: pass-in contact list data
    render->init(data);
}

void
FxContactListWidget::setupComplexView()
{
    FX_FUNCTION
}

void
FxContactListWidget::slotHandleClvUpdate(QList<FxContact *> *cld)
{
    FX_FUNCTION
    data = cld;
}
