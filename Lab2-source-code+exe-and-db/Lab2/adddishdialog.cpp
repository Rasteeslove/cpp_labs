#include "adddishdialog.h"
#include "ui_adddishdialog.h"

#include "mainwindow.h"

addDishDialog::addDishDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDishDialog)
{
    ui->setupUi(this);
}

addDishDialog::~addDishDialog()
{
    delete ui;
}

void addDishDialog::on_cancelButton_clicked()
{
    addDishDialog::close();
}

void addDishDialog::on_confirmButton_clicked()
{
    // checking input
    if (ui->nameEdit->text().isEmpty() || ui->priceSpinBox->value() == 0)
        return;

    // adding dish to the menu
    QString description_line = ui->descriptionEdit->toPlainText();
    QStringList description = description_line.split(QRegExp("[\n]"),QString::SkipEmptyParts);

    dish new_dish(menu_dishes, ui->nameEdit->text(), description, ui->priceSpinBox->value());
    menu_dishes.push_back(new_dish);

    addDishDialog::close();
}
