#ifndef SIDELINK_H
#define SIDELINK_H


#include <QGraphicsLineItem>
#include "graphwidget.h"

class Connector;
class Anchor;

class SideLink : public QGraphicsLineItem
{
public:
    SideLink(GraphWidget *graphWidget, Anchor *startAnchor, Connector *endConnector);


    Anchor *StartAnchor() const { return startAnchor; }
    Connector *EndConnector() const { return endConnector; }

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

    void adjust();
    void setColor(const QColor& color) { colorOfSideLink = color; }

private:
    Anchor *startAnchor;
    Connector *endConnector;
    QPointF startPos;
    QPointF endPos;
    QColor colorOfSideLink;
    GraphWidget *graph;
};

#endif // SIDELINK_H
