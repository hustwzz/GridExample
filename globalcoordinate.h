#ifndef GLOBALCOORDINATE_H
#define GLOBALCOORDINATE_H

#include <QGraphicsEllipseItem>

class GlobalCoordinate:public QGraphicsEllipseItem
{
public:
    GlobalCoordinate(QGraphicsItem *parent = nullptr);

private:
    QGraphicsLineItem *xAxis;
    QGraphicsLineItem *yAxis;
    QGraphicsPolygonItem *xArrow;
    QGraphicsPolygonItem *yArrow;
    QGraphicsTextItem *xLabel;
    QGraphicsTextItem *yLabel;
    QGraphicsTextItem *Origin;

    qreal axisWidth;
    QColor axisColor;

    QPolygonF xHead;
    QPolygonF yHead;

    qreal originFontSize;
    qreal xyFontSize;
};

#endif // GLOBALCOORDINATE_H
