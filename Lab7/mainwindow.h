#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void displayHTable();
    void freeTWMemory();
    void refreshCollisions();

private slots:
    void on_add_item_button_clicked();

    void on_add_number_of_numbers_button_clicked();

    void on_rmv_item_button_clicked();

    void on_rmv_in_range_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
