#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QGraphicsEllipseItem>
#include "graphwidget.h"
#include "coupler.h"
#include "sidelink.h"
#include <QList>

class Connector:public QGraphicsEllipseItem
{
public:
    Connector(GraphWidget *graphWidget,const QPointF& point1,const QPointF& point2 = QPointF(0,0));
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

    QPointF PosInScene() const { return posInScene; }
    void addCoupler(Coupler *cp) { couplers.append(cp);}
    void addSideLink(SideLink *lk) { link = lk; }

    void advance(int phase);
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) Q_DECL_OVERRIDE;
private:
    QPointF posInScene;
    QPointF centerPos;
    QList<Coupler *> couplers;
    SideLink *link;

    GraphWidget *graph;
};

#endif // CONNECTOR_H
