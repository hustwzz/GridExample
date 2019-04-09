#ifndef ANCHORDIALOG_H
#define ANCHORDIALOG_H

#include <QDialog>
#include <QGraphicsItem>
#include "anchor.h"

namespace Ui {
class AnchorDialog;
}

class AnchorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AnchorDialog(Anchor *anchor, QWidget *parent = 0);
    ~AnchorDialog();
    void accept();

public slots:
    void changeAngleUnit(int index);

signals:
    void changePosInScene(QPointF);
    void changeIsFixed(bool);
    void changeAnchorAngle(qreal);

private:
    Ui::AnchorDialog *ui;
    QPointF _posInScene;
    qreal _anchorAngle;
    bool _isFixed;
};

#endif // ANCHORDIALOG_H
