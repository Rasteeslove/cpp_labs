#include "dishinfodialog.h"
#include "ui_dishinfodialog.h"

#include <QString>
#include <QStringList>

dishInfoDialog::dishInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dishInfoDialog)
{
    ui->setupUi(this);

}

dishInfoDialog::~dishInfoDialog()
{
    delete ui;
}

void dishInfoDialog::displayInfo(dish * d)
{
    ui->label->setText(d->name);
    QString description = d->description.join("\n");
    ui->textBrowser->setText(description);
}
