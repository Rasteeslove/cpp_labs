#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>

#include "dish.h"
#include "order.h"
#include "adddishdialog.h"
#include "tablewidgetnumberitem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void displayMenu();
    void freeMenuMemory();
    void displayCurrentOrder();
    void displayOrders();

private slots:
    void on_addNewDishButton_clicked();

    void on_addDishesButton_clicked();

    void on_pushButton_5_clicked();

    void on_removeSelectedDishes_clicked();

    void on_removeDishesButton_clicked();

    void on_filter_currentIndexChanged(int index);

    void on_dishesTable_cellDoubleClicked(int row, int column);

private:
    Ui::MainWindow *ui;
};

extern std::vector<dish> menu_dishes;

#endif // MAINWINDOW_H
