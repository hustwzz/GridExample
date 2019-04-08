#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

class GraphicsView:public QGraphicsView
{
public:
    GraphicsView(QWidget* parent = nullptr);
    void zoomIn();
    void zoomOut();
    void setGirdSpace(int space);
    int getGridSpace() const { return m_gridSpace; }
    void setHasGrid(bool hasGrid);
    bool getHasGrid() const { return m_hasGrid; }
protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);
    void scaleView(qreal scaleFactor);

signals:
    void startAnimation();

private:
    int m_gridSpace;
    bool m_hasGrid;
};

#endif // GRAPHICSVIEW_H
