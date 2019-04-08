#include "graphwidget.h"
#include <QDebug>
#include <QScrollBar>


GraphWidget::GraphWidget(QWidget* parent)
: QGraphicsView(parent), timerId(0),isTranslated(false)
{
    setDragMode(QGraphicsView::RubberBandDrag);
    setRenderHint(QPainter::Antialiasing);
    scale(qreal(0.8), qreal(0.8));
    setMinimumSize(400, 400);
    setMouseTracking(true);
}

void GraphWidget::scaleView(qreal scaleFactor)
{
     qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
     if (factor < 0.6 || factor > 10)
         return;

     scale(scaleFactor, scaleFactor);
}



void GraphWidget::zoomIn()
{
     scaleView(qreal(1.2));
}

void GraphWidget::zoomOut()
{
    scaleView(1/qreal(1.2));
}

void GraphWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MidButton || event->button() == Qt::RightButton)
    {
        isTranslated = true;
        lastPos = event->pos();
    }
    QGraphicsView::mousePressEvent(event);
}

void GraphWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(isTranslated)
    {
        QPoint deltaPos = event->pos()-lastPos;
        QScrollBar *hBar = horizontalScrollBar();
        QScrollBar *vBar = verticalScrollBar();

        hBar->setValue(hBar->value() - deltaPos.x());
        vBar->setValue(vBar->value() - deltaPos.y());
    }
    lastPos = event->pos();
    QGraphicsView::mouseMoveEvent(event);
}

void GraphWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MidButton || event->button() == Qt::RightButton)
        isTranslated = false;

    QGraphicsView::mouseReleaseEvent(event);
}



void GraphWidget::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, -event->delta() / 240.0));
}
