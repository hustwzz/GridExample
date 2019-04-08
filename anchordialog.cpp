#include "anchordialog.h"
#include "ui_anchordialog.h"
#include <QDebug>

AnchorDialog::AnchorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnchorDialog)
{
    ui->setupUi(this);

    ui->comboBox->addItem(tr("deg"));
    ui->comboBox->addItem(tr("rad"));
    ui->comboBox->setCurrentIndex(0);

}

AnchorDialog::~AnchorDialog()
{
    delete ui;
}

void AnchorDialog::accept()
{
    qDebug() << 1;
    QDialog::accept();
}
