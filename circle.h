#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include "graphicsview.h"

class Circle:public QGraphicsEllipseItem
{
public:
    Circle(GraphicsView* view);
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) Q_DECL_OVERRIDE;
    QPointF checkGrid(int space);
    void advance(int phase);
private:
    GraphicsView* View;
};

#endif // CIRCLE_H
