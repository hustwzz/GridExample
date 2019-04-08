#include "graphicsview.h"
#include <QMouseEvent>
#include <QWheelEvent>

GraphicsView::GraphicsView(QWidget *parent):QGraphicsView(parent)
{
    m_hasGrid = false;
    m_gridSpace = 50;
    setDragMode(QGraphicsView::RubberBandDrag);
    setRenderHint(QPainter::Antialiasing);
    scale(qreal(0.8), qreal(0.8));
    setMinimumSize(400, 400);
    setMouseTracking(true);
}

void GraphicsView::zoomIn()
{
    scaleView(1/1.2);
}

void GraphicsView::zoomOut()
{
    scaleView(1.2);
}

void GraphicsView::setGirdSpace(int space)
{
    m_gridSpace = space;
}

void GraphicsView::setHasGrid(bool hasGrid)
{
    m_hasGrid = hasGrid;
}

void GraphicsView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}

void GraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
}

void GraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
}

void GraphicsView::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, -event->delta() / 240.0));
    QGraphicsView::wheelEvent(event);
}

void GraphicsView::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor,scaleFactor).mapRect(QRect(0,0,1,1)).width();
    if(factor < 0.6 || factor > 10)
        return;
    scale(scaleFactor,scaleFactor);
}

