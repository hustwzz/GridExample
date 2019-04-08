#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphicsview.h"
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addGrid();

private slots:
    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_actionStart_triggered();

    void on_actionStop_triggered();

private:
    Ui::MainWindow *ui;
    GraphicsView *View;
    QGraphicsScene *scene;
    QGraphicsItemGroup *group;
    QTimer *m_animation_timer;
};

#endif // MAINWINDOW_H
