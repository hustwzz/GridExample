#ifndef ANCHORDIALOG_H
#define ANCHORDIALOG_H

#include <QDialog>
#include <QGraphicsItem>

namespace Ui {
class AnchorDialog;
}

class AnchorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AnchorDialog(QWidget *parent = 0);
    ~AnchorDialog();
    void accept();

private:
    Ui::AnchorDialog *ui;
};

#endif // ANCHORDIALOG_H
