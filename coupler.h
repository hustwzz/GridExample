#ifndef COUPLER_H
#define COUPLER_H

#include <QGraphicsLineItem>
#include "graphwidget.h"

class Connector;

class Coupler : public QGraphicsLineItem
{
public:
    Coupler(GraphWidget *graphWidget, Connector *connector1, Connector *connector2);

    Connector *StartConnector() const { return startConnector; }
    Connector *EndConnector() const { return endConnector; }

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

    void adjust();

private:
    Connector *startConnector,*endConnector;
    QPointF startPos;
    QPointF endPos;
    GraphWidget *graph;
};

#endif // COUPLER_H
