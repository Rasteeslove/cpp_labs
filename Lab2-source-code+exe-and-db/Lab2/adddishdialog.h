#ifndef ADDDISHDIALOG_H
#define ADDDISHDIALOG_H

#include <QDialog>



namespace Ui {
class addDishDialog;
}

class addDishDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addDishDialog(QWidget *parent = nullptr);
    ~addDishDialog();

private slots:
    void on_cancelButton_clicked();

    void on_confirmButton_clicked();

private:
    Ui::addDishDialog *ui;
};

#endif // ADDDISHDIALOG_H
