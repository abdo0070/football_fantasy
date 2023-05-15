#include "events.h"

Events::Events()
{

}


Custom_Graphics_View::Custom_Graphics_View(QWidget *widget) : QGraphicsView(widget)
{
    setAcceptDrops(true);
}

void Custom_Graphics_View::dropEvent(QDropEvent *event)
{
    QListWidget *listwidget = qobject_cast<QListWidget*>(event->source());

}

void Custom_Graphics_View::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
    event->acceptProposedAction();
}

void Custom_Graphics_View::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

void Custom_Graphics_View::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
    event->acceptProposedAction();
}
