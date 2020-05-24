#include "addorderdialog.h"
#include "ui_addorderdialog.h"

#include "order.h"

AddOrderDialog::AddOrderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddOrderDialog)
{
    ui->setupUi(this);
}

AddOrderDialog::~AddOrderDialog()
{
    delete ui;
}

void AddOrderDialog::on_pushButton_2_clicked()
{
    this->close();
}

void AddOrderDialog::on_pushButton_clicked()
{
    order new_order(all, ui->lineEdit->text().simplified(), ui->lineEdit_2->text().simplified(),
                    ui->lineEdit_3->text().simplified(), QDate::currentDate());

    all.push_back(new_order);
    this->close();
}

void AddOrderDialog::on_lineEdit_textChanged(const QString &arg1)
{
    if (arg1.length() >= 2 && ui->lineEdit_2->text().length() >= 2)
        ui->pushButton->setEnabled(true);
    else
        ui->pushButton->setEnabled(false);
}

void AddOrderDialog::on_lineEdit_2_textChanged(const QString &arg1)
{
    if (arg1.length() >= 2 && ui->lineEdit->text().length() >= 2)
        ui->pushButton->setEnabled(true);
    else
        ui->pushButton->setEnabled(false);
}
