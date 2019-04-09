#include "anchor.h"
#include "anchordialog.h"

#include <cmath>
#include <QGraphicsSceneMouseEvent>
#include <QToolTip>

#define PI 3.1415926

Anchor::Anchor(const QPointF &point1, const QPointF &point2)
    :posInScene(point1),anchorPosition(point2),link(nullptr),isFixed(false),anchorAngle(0)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setFlag(ItemIsSelectable);
    setPos(posInScene);
    posInScene.setY(-posInScene.y());

    setAcceptHoverEvents(true);
}

QRectF Anchor::boundingRect() const
{
    qreal adjust = 1;
    return QRectF( -10 - adjust, -3 - adjust, 22 + adjust, 17 + adjust);
}

void Anchor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    //绘制固定铰链
    QPen pen(Qt::NoBrush,1);
    pen.setColor(QColor(Qt::blue).light(120));
    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawEllipse(anchorPosition,3,3);
    QPointF pos1(anchorPosition.x()-3*cos(PI/3),anchorPosition.y()+3*sin(PI/3));
    QPointF pos2(anchorPosition.x()-10*cos(PI/3),anchorPosition.y()+10*sin(PI/3));
    QPointF pos3(anchorPosition.x()+3*cos(PI/3),anchorPosition.y()+3*sin(PI/3));
    QPointF pos4(anchorPosition.x()+10*cos(PI/3),anchorPosition.y()+10*sin(PI/3));
    QPointF pos5(pos2.x()-5,pos2.y());
    QPointF pos6(pos4.x()+5,pos4.y());

    qreal l = pos6.x()-pos5.x();

    QPointF pos7(pos5.x()+l*2/11.0,pos5.y());
    QPointF pos8(pos5.x()+l*4.5/11.0,pos5.y());
    QPointF pos9(pos5.x()+l*7.5/11.0,pos5.y());
    QPointF pos10(pos5.x()+l*10/11.0,pos5.y());

    painter->drawLine(pos1,pos2);
    painter->drawLine(pos3,pos4);
    painter->drawLine(pos5,pos6);
    painter->drawLine(pos7,QPointF(pos7.x()-4,pos7.y()+4));
    painter->drawLine(pos8,QPointF(pos8.x()-4,pos8.y()+4));
    painter->drawLine(pos9,QPointF(pos9.x()-4,pos9.y()+4));
    painter->drawLine(pos10,QPointF(pos10.x()-4,pos10.y()+4));

}

void Anchor::setAnchorAngle(qreal angle)
{
    anchorAngle = angle;
    setRotation(angle);
}

void Anchor::setPosInScene(QPointF point)
{
    posInScene.setX(point.x());
    posInScene.setY(-point.y());
    setPos(point);
}

void Anchor::setIsFixedOrUnFixed(bool isFixedOrNot)
{
    isFixed = isFixedOrNot;
}

void Anchor::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    posInScene.setX(mapToScene(event->pos()).x());
    posInScene.setY(-mapToScene(event->pos()).y());
    QGraphicsItem::mouseMoveEvent(event);
}

void Anchor::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        AnchorDialog anchorDialog(this);
        connect(&anchorDialog,SIGNAL(changeAnchorAngle(qreal)),this,SLOT(setAnchorAngle(qreal)));
        connect(&anchorDialog,SIGNAL(changePosInScene(QPointF)),this,SLOT(setPosInScene(QPointF)));
        anchorDialog.exec();
    }
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void Anchor::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setCursor(Qt::OpenHandCursor);
    setToolTip("固定铰链");
    QGraphicsItem::hoverEnterEvent(event);
}

void Anchor::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setCursor(Qt::ArrowCursor);
    QGraphicsItem::hoverLeaveEvent(event);
}

QVariant Anchor::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        if(link!=nullptr)  link->adjust();
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}




