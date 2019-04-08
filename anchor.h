#ifndef ANCHOR_H
#define ANCHOR_H

#include <QGraphicsItem>
#include "graphwidget.h"
#include "sidelink.h"

class Anchor : public QGraphicsItem
{
public:
    Anchor(GraphWidget *graphWidget,const QPointF& point1,const QPointF& point2 = QPointF(0,0));

    void addLink(SideLink *lk) { link = lk; }
    SideLink *AnchorLink() const {return link;}

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) Q_DECL_OVERRIDE;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) Q_DECL_OVERRIDE;
     QVariant itemChange(GraphicsItemChange change, const QVariant &value) Q_DECL_OVERRIDE;

private:
    QPointF anchorPosition;
    QPointF posInScene;
    SideLink *link;
    GraphWidget *graph;


};

#endif // ANCHOR_H
