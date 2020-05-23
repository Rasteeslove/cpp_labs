#include <vector>

#include <QFile>
#include <QDataStream>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dishinfodialog.h"
#include "orderinfodialog.h"

std::vector<dish> menu_dishes;
std::vector<order> orders;
order current_order;

void MainWindow::freeMenuMemory()
{
    for (int i = 0; i < ui->dishesTable->rowCount(); i++)
         for (int j = 0; j < 3; j++)
             delete ui->dishesTable->item(i, j);

    ui->dishesTable->setRowCount(0);
}

void MainWindow::displayMenu()
{
    ui->dishesTable->setSortingEnabled(false);

    freeMenuMemory();
    for (size_t i = 0; i < menu_dishes.size(); i++)
        if (menu_dishes[i].is_on_the_menu)
        {
            ui->dishesTable->insertRow(ui->dishesTable->rowCount());
            QTableWidgetItem * name = new QTableWidgetItem(menu_dishes[i].name);
            name->setFlags(name->flags() ^ Qt::ItemIsEditable);

            // associating QTableWidgetItem with dish'es id
            name->setData(Qt::UserRole, menu_dishes[i].id);

            ui->dishesTable->setItem(i, 0, name);
            TableWidgetNumberItem * popularity = new TableWidgetNumberItem(QString::
                                                                          number(menu_dishes[i].popularity));
            popularity->setFlags(popularity->flags() ^ Qt::ItemIsEditable);
            ui->dishesTable->setItem(i, 1, popularity);

            TableWidgetNumberItem * price = new TableWidgetNumberItem(QString("%1").arg(menu_dishes[i].price,
                                                                                        0, 'f', 2, QChar('0')));
            price->setFlags(price->flags() ^ Qt::ItemIsEditable);
            ui->dishesTable->setItem(i, 2, price);
        }

    ui->dishesTable->setSortingEnabled(true);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand( (unsigned)time(NULL) );
    ui->setupUi(this);

    qRegisterMetaTypeStreamOperators<dish>("Dish");
    qRegisterMetaTypeStreamOperators<order>("Order");

    // getting menu dishes from file
    QFile file1("dishes.txt");
    if (!file1.open(QIODevice::ReadOnly)) {
             QMessageBox::information(this, tr("error loading data from file."),
                 file1.errorString());
             return;
    }
    QDataStream in1(&file1);
    in1.setVersion(QDataStream::Qt_4_8);
    while (!file1.atEnd())
    {
        dish tmp;
        in1 >> tmp;
        menu_dishes.push_back(tmp);
    }
    file1.close();

    // getting orders from file
    QFile file2("orders.txt");
    if (!file2.open(QIODevice::ReadOnly)) {
             QMessageBox::information(this, tr("error loading data from file."),
                 file2.errorString());
             return;
    }
    QDataStream in2(&file2);
    in2.setVersion(QDataStream::Qt_4_8);
    while (!file2.atEnd())
    {
        order tmp;
        in2 >> tmp;
        orders.push_back(tmp);
    }
    file2.close();

    // displaying them
    displayMenu();
    displayCurrentOrder();
    displayOrders();
}

MainWindow::~MainWindow()
{
    // writing menu dishes to file
    QFile file1("dishes.txt");
    if (!file1.open(QIODevice::WriteOnly)) {
             QMessageBox::information(this, tr("error loading data to file."),
                 file1.errorString());
             return;
    }
    QDataStream out1(&file1);
    out1.setVersion(QDataStream::Qt_4_8);
    for (size_t i = 0; i < menu_dishes.size(); i++)
        out1 << menu_dishes[i];
    file1.close();

    // writing orders to file
    QFile file2("orders.txt");
    if (!file2.open(QIODevice::WriteOnly)) {
             QMessageBox::information(this, tr("error loading data to file."),
                 file2.errorString());
             return;
    }
    QDataStream out2(&file2);
    out2.setVersion(QDataStream::Qt_4_8);
    for (size_t i = 0; i < orders.size(); i++)
        out2 << orders[i];
    file2.close();

    delete ui;
}

void MainWindow::on_addNewDishButton_clicked()
{
    addDishDialog dialog;
    dialog.setModal(true);
    dialog.exec();

    displayMenu();
}

dish * get_dish_by_id(size_t id)
{
    for (size_t i = 0; i < menu_dishes.size(); i++)
        if (menu_dishes[i].id == id)
            return &menu_dishes[i];

    return nullptr;
}

void MainWindow::displayCurrentOrder()
{
    double sum = 0;
    ui->currentOrder->clear();
    for (size_t i = 0; i < current_order.dishes.size(); i++)
    {
        dish * tmp = get_dish_by_id(current_order.dishes[i].first);
        ui->currentOrder->addItem(tr("x%1 of %2, %3$ each").arg(current_order.dishes[i].second)
                                  .arg(tmp->name).arg(tmp->price));
        sum += tmp->price * current_order.dishes[i].second;
    }
    current_order.sum = sum;

    if (current_order.dishes.empty())
    {
        ui->currentOrder->addItem("No dishes are ordered.");
    }
    else
    {
        ui->currentOrder->addItem("----------------------");
        ui->currentOrder->addItem(tr("%1$ for everything.").arg(sum));
    }
}

void MainWindow::on_addDishesButton_clicked()
{
    // getting selected and checking
    QModelIndexList selection = ui->dishesTable->selectionModel()->selectedRows();
    if (selection.isEmpty())
        return;

    // getting the first (it must be also last) of selected
    QModelIndex index = selection.at(0);

    // getting dish'es id
    size_t tmp = ui->dishesTable->item(index.row(), 0)->data(Qt::UserRole).value<size_t>();

    // adding
    bool is_present = false;
    for (size_t i = 0; i < current_order.dishes.size(); i++)
        if (current_order.dishes[i].first == tmp)
        {
            current_order.dishes[i].second += ui->quantitySpin->value();
            if (current_order.dishes[i].second > 9)
                current_order.dishes[i].second = 9;
            is_present = true;
            break;
        }

    if (!is_present)
        current_order.dishes.push_back(std::pair<size_t, size_t>(
                                       tmp,
                                       ui->quantitySpin->value()
                                                            )
                                  );

    // refreshing current order list widget
    displayCurrentOrder();
}

void MainWindow::displayOrders()
{
    int index = ui->filter->currentIndex();

    int days = -1;
    switch (index)
    {
    case 0:
        days = 0;
        break;
    case 1:
        days = 7;
        break;

    case 2:
        days = 30;
        break;
    }

    ui->allOrdersListWidget->clear();
    for (size_t i = 0; i < orders.size(); i++)
        if (days == -1 || orders[i].date.daysTo(QDate::currentDate()) <= days)
        {
            int dishes_num = 0;
            for (size_t j = 0; j < orders[i].dishes.size(); j++)
                dishes_num += orders[i].dishes[j].second;
            ui->allOrdersListWidget->addItem(tr("%1 dishes for %2$ at table #%3 on ").arg(dishes_num)
                                             .arg(orders[i].sum).arg(orders[i].table_num) + orders[i].date.toString("dd.MM.yyyy"));
        }

    if (ui->allOrdersListWidget->count() == 0)
        ui->allOrdersListWidget->addItem("no results");
}

void MainWindow::on_pushButton_5_clicked()
{
    if (current_order.dishes.empty())
        return;

    order new_order(current_order);
    new_order.table_num = ui->tableNumSpin->value();
    new_order.date = QDate::currentDate();

    // changing dishes'popularity
    for (size_t i = 0; i < new_order.dishes.size(); i++)
        get_dish_by_id(new_order.dishes[i].first)->popularity += new_order.dishes[i].second;
    displayMenu();

    orders.push_back(new_order);
    displayOrders();

    current_order.dishes.clear();
    current_order.sum = 0;
    displayCurrentOrder();
}

void MainWindow::on_removeSelectedDishes_clicked()
{
    // getting selected and checking
    QModelIndexList selection = ui->dishesTable->selectionModel()->selectedRows();
    if (selection.isEmpty())
        return;

    // getting the first (it must be also last) of selected
    QModelIndex index = selection.at(0);

    // getting dish'es id
    size_t tmp = ui->dishesTable->item(index.row(), 0)->data(Qt::UserRole).value<size_t>();

    dish * to_remove = get_dish_by_id(tmp);
    to_remove->is_on_the_menu = false;

    displayMenu();
}

void MainWindow::on_removeDishesButton_clicked()
{
    if (ui->currentOrder->selectionModel()->selectedRows().empty())
        return;

    size_t index = ui->currentOrder->selectionModel()->selectedRows()[0].row();
    if (index < current_order.dishes.size())
        current_order.dishes.erase(current_order.dishes.begin() + index);

    displayCurrentOrder();
}

void MainWindow::on_filter_currentIndexChanged(int index)
{
    displayOrders();
}

void MainWindow::on_dishesTable_cellDoubleClicked(int row, int column)
{
    size_t id = ui->dishesTable->item(row, 0)->data(Qt::UserRole).value<size_t>();

    dish * d = get_dish_by_id(id);

    dishInfoDialog dialog;
    dialog.displayInfo(d);

    dialog.setModal(true);
    dialog.exec();
}
