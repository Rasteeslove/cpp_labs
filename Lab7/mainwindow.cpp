#include <limits>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRandomGenerator>

#include "hashtable.h"

hashTable<int> main_table(51);
unsigned int num_of_collisions = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::freeTWMemory()
{
    for (int i = 0; i < ui->hash_tablewidget->rowCount(); i++)
        for (int j = 0; j < ui->hash_tablewidget->columnCount(); j++)
            //if (ui->hash_tablewidget->item(i, j) != nullptr)
                delete ui->hash_tablewidget->item(i, j);
}

void MainWindow::displayHTable()
{
    freeTWMemory();
    ui->hash_tablewidget->setColumnCount(main_table.size());
    ui->hash_tablewidget->setRowCount(main_table.height());

    std::vector<std::pair<Stack<int>, unsigned int>> table = main_table.toStdVector();
    for (int i = 0; i < ui->hash_tablewidget->columnCount(); i++)
    {
        QTableWidgetItem * key = new QTableWidgetItem(QString::number(table[i].second));
        key->setData(Qt::UserRole, table[i].second);
        key->setBackgroundColor(Qt::gray);

        ui->hash_tablewidget->setHorizontalHeaderItem(i, key);

        for (int j = 0; !table[i].first.isEmpty(); j++)
        {
            QTableWidgetItem * item = new QTableWidgetItem(QString::number(table[i].first.pop()));
            item->setBackgroundColor(Qt::lightGray);
            ui->hash_tablewidget->setItem(j, i, item);
        }
    }

}

void MainWindow::on_add_item_button_clicked()
{
    QString entered = ui->input_item_edit->text();
    bool is_number;

    int newItem = entered.toInt(&is_number);
    if (!is_number)
        return;

    bool collision = main_table.addNumber(newItem);
    if (collision)
        num_of_collisions++;

    displayHTable();
    refreshCollisions();
}

void MainWindow::on_add_number_of_numbers_button_clicked()
{
    QString entered = ui->input_item_edit->text();
    bool is_number;

    int itemNum = entered.toInt(&is_number);
    if (!is_number || itemNum <= 0)
        return;

    for (int i = 0; i < itemNum; i++)
    {
        bool collision = main_table.addNumber(QRandomGenerator::global()->generate());
        if (collision)
            num_of_collisions++;
    }

    displayHTable();
    refreshCollisions();
}

void MainWindow::on_rmv_item_button_clicked()
{
    QList<QTableWidgetItem*> list = ui->hash_tablewidget->selectedItems();
    if (list.empty())
        return;

    unsigned int index = list[0]->row();
    unsigned int column_in_tw = list[0]->column();

    unsigned int index_in_main_table = ui->hash_tablewidget->horizontalHeaderItem(column_in_tw)->
            data(Qt::UserRole).value<unsigned int>();
    Stack<int> * to_change = main_table.getStackPtrAtIndex(index_in_main_table);

    to_change->rmv_at(index);

    displayHTable();
    refreshCollisions();
}

void MainWindow::on_rmv_in_range_button_clicked()
{
    QString from = ui->from_edit->text();
    QString to = ui->to_edit->text();
    bool check1 = true, check2 = true;

    if (from.isEmpty() && to.isEmpty())
        return;

    int from_key;
    if (from.isEmpty()) from_key = INT_MIN;
    else from_key = from.toInt(&check1);

    int to_key;
    if (to.isEmpty()) to_key = INT_MAX;
    else to_key = to.toInt(&check2);

    if (!check1 || !check2)
        return;

    main_table.rmv_items_in_range(from_key, to_key);
    displayHTable();
    refreshCollisions();
}

void MainWindow::refreshCollisions()
{
    num_of_collisions = 0;
    for (unsigned int i = 0; i < main_table.capacity(); i++)
        if (!main_table.getStackAtIndex(i).isEmpty())
            num_of_collisions += (main_table.getStackAtIndex(i).getSize() - 1);

    ui->collisions_num_label->setText("Collisions: " + QString::number(num_of_collisions));
}


