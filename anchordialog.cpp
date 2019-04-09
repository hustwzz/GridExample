#include "anchordialog.h"
#include "ui_anchordialog.h"

#define PI 3.1415926

AnchorDialog::AnchorDialog(Anchor *anchor, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnchorDialog),
    _posInScene(anchor->getPosInScene()),
    _anchorAngle(anchor->getAnchorAngle()),
    _isFixed(anchor->isFixedOrUnfixed())
{
    ui->setupUi(this);

    ui->comboBox->addItem(tr("deg"));
    ui->comboBox->addItem(tr("rad"));
    ui->comboBox->setCurrentIndex(0);

    ui->lineEdit->setText(QString("%1").arg(_posInScene.x()));
    ui->lineEdit_2->setText(QString("%1").arg(_posInScene.y()));
    ui->lineEdit_3->setText(QString("%1").arg(_anchorAngle));

    ui->checkBox->setChecked(_isFixed);

    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(changeAngleUnit(int)));
}

AnchorDialog::~AnchorDialog()
{
    delete ui;
}

void AnchorDialog::accept()
{
    QString angleStr = ui->lineEdit_3->text();
    if(ui->comboBox->currentIndex() == 0)
        emit changeAnchorAngle(-angleStr.toDouble());
    else if(ui->comboBox->currentIndex() == 1)
        emit changeAnchorAngle(-angleStr.toDouble()*180.0/PI);

    emit changePosInScene(QPointF(ui->lineEdit->text().toDouble(),-ui->lineEdit_2->text().toDouble()));
    emit changeIsFixed(ui->checkBox->isCheckable());

    QDialog::accept();
}

void AnchorDialog::changeAngleUnit(int index)
{
    QString currentAngle = ui->lineEdit_3->text();

    if(index == 0)
        ui->lineEdit_3->setText(QString("%1").arg(currentAngle.toDouble()/PI*180.0));
    else if(index == 1)
        ui->lineEdit_3->setText(QString("%1").arg(currentAngle.toDouble()*PI/180.0));
}
