#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <QMouseEvent>

class GraphWidget : public QGraphicsView
{
public:
    GraphWidget(QWidget *parent = 0);

public slots:
    void zoomIn();
    void zoomOut();

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
    void scaleView(qreal scaleFactor);

private:
    int timerId;
    bool isTranslated;  //是否平移
    QPoint lastPos;
};

#endif // GRAPHWIDGET_H
