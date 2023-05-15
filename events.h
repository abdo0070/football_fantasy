#ifndef EVENTS_H
#define EVENTS_H

#include <QGraphicsView>
#include <QListWidget>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>

class Events
{
public:
    Events();
};

class Custom_Graphics_View : public QGraphicsView
{
    Q_OBJECT
signals:
    void itemDrop(QString);
public:
    explicit Custom_Graphics_View(QWidget *widget = nullptr);
protected:
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    using QGraphicsView::QGraphicsView;
};

#endif // EVENTS_H
