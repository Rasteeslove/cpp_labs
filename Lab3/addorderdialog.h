#ifndef ADDORDERDIALOG_H
#define ADDORDERDIALOG_H

#include <QDialog>

namespace Ui {
class AddOrderDialog;
}

class AddOrderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddOrderDialog(QWidget *parent = nullptr);
    ~AddOrderDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::AddOrderDialog *ui;
};

#endif // ADDORDERDIALOG_H
