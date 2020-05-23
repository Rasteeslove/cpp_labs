#ifndef DISHINFODIALOG_H
#define DISHINFODIALOG_H

#include <QDialog>

#include "dish.h"

namespace Ui {
class dishInfoDialog;
}

class dishInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit dishInfoDialog(QWidget *parent = nullptr);
    ~dishInfoDialog();

    void displayInfo(dish * d);

private:
    Ui::dishInfoDialog *ui;
};

#endif // DISHINFODIALOG_H
