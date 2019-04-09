#ifndef ANCHOR_H
#define ANCHOR_H

#include <QGraphicsItem>
#include "sidelink.h"

class Anchor :public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Anchor(const QPointF& point1,const QPointF& point2 = QPointF(0,0));

    void addSideLink(SideLink *lk) { link = lk; }
    SideLink *getSideLink() const { return link; }
    QPointF getPosInScene() const { return posInScene; }
    qreal getAnchorAngle() const { return -anchorAngle; }
    bool isFixedOrUnfixed() const { return isFixed; }

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

public slots:
    void setAnchorAngle(qreal angle);
    void setPosInScene(QPointF point);
    void setIsFixedOrUnFixed(bool isFixedOrNot);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) Q_DECL_OVERRIDE;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) Q_DECL_OVERRIDE;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) Q_DECL_OVERRIDE;

private:
    QPointF anchorPosition;
    QPointF posInScene;
    qreal anchorAngle;

    SideLink *link;
    bool isFixed;
};

#endif // ANCHOR_H
