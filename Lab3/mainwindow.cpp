#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addorderdialog.h"

#include "order.h"

d_list<order> all;

class TableWidgetDateItem : public QTableWidgetItem
{
public:

    TableWidgetDateItem(QString str) : QTableWidgetItem(str) {}

    bool operator < (const QTableWidgetItem &other) const
    {
        if (this->text() == "-")
            return true;

        QDate t = QDate::fromString(this->text(), "dd.MM.yyyy");
        QDate o = QDate::fromString(other.text(), "dd.MM.yyyy");

        return t.daysTo(o) < 0;
    }

};

void MainWindow::freeTable()
{
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
        for (int j = 0; j < 4; j++)
            delete ui->tableWidget->item(i, j);
    ui->tableWidget->setRowCount(0);
}

void MainWindow::displayOrders()
{
    ui->tableWidget->setSortingEnabled(false);

    freeTable();

    int filter1;
    if (ui->radioButton->isChecked())
        filter1 = 0;
    else if (ui->radioButton_2->isChecked())
        filter1 = 1;
    else
        filter1 = 2;

    int filter2;
    if (ui->comboBox->currentIndex() == 0)
        filter2 = 0;
    else if (ui->comboBox->currentIndex() == 1)
        filter2 = 1;
    else
        filter2 = 2;

    d_list<order> filtered1;
    for (int i = 0; i < all.get_length(); i++)
        if ((filter1 == 0 && all[i].is_completed == false) ||
            (filter1 == 1 && all[i].is_completed == true) ||
            filter1 == 2)
        filtered1.push_back(all[i]);

    if (filtered1.is_empty())
        return;

    d_list<order> filtered2;
    for (int i = 0; i < filtered1.get_length(); i++)
        if ((filter2 == 0 && filtered1[i].first_name.lastIndexOf(ui->lineEdit->text()) != -1) ||
            (filter2 == 1 && filtered1[i].last_name.lastIndexOf(ui->lineEdit->text()) != -1) ||
            (filter2 == 2 && filtered1[i].added.toString("dd.MM.yyyy").
                lastIndexOf(ui->lineEdit->text()) != -1))
            filtered2.push_back(filtered1[i]);

    if (filtered2.is_empty())
        return;

    for (int i = 0; i < filtered2.get_length(); i++)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        {

        QTableWidgetItem * tmp = new QTableWidgetItem(filtered2[i].added.toString("dd.MM.yyyy"));

        tmp = new QTableWidgetItem(filtered2[i].first_name);
        tmp->setFlags(tmp->flags() ^ Qt::ItemIsEditable);
        tmp->setData(Qt::UserRole, filtered2[i].id);
        ui->tableWidget->setItem(i, 0, tmp);

        tmp = new QTableWidgetItem(filtered2[i].last_name);
        tmp->setFlags(tmp->flags() ^ Qt::ItemIsEditable);
        ui->tableWidget->setItem(i, 1, tmp);

        }

        TableWidgetDateItem * tmp;
        tmp = new TableWidgetDateItem(filtered2[i].added.toString("dd.MM.yyyy"));
        tmp->setFlags(tmp->flags() ^ Qt::ItemIsEditable);
        ui->tableWidget->setItem(i, 2, tmp);

        tmp = new TableWidgetDateItem(filtered2[i].is_completed ?
                                       filtered2[i].completed.toString("dd.MM.yyyy") : "-");
        tmp->setFlags(tmp->flags() ^ Qt::ItemIsEditable);
        ui->tableWidget->setItem(i, 3, tmp);
    }

    ui->tableWidget->setSortingEnabled(true);
}

order * get_order_by_id(d_list<order> group, size_t id)
{
    for (int i = 0; i < group.get_length(); i++)
        if (group[i].id == id)
            return &group[i];

    return nullptr;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(0));

    ui->setupUi(this);

    QDate a(2020, 2, 20);
    order order_a(all, "John", "Smith", "4058  Kelley Road, New Orleans, MS", a);

    QDate b(2019, 10, 10);
    order order_b(all, "Ronald", "Dorsey", "4893  Ashcraft Court, Imperial Beach, CA", b);

    QDate c(2019, 12, 8);
    order order_c(all, "Melissa", "Jarrell", "2489  Heliport Loop, Terre Haute, IN", c);
    order_c.is_completed = true;
    QDate cc(2020, 4, 4);
    order_c.completed = cc;

    QDate d(2019, 3, 14);
    order order_d(all, "Jason", "Godinez", "3722  Spadafore Drive, Clearfield, PA", d);
    order_d.is_completed = true;
    QDate dc(2019, 8, 8);
    order_d.completed = dc;

    QDate e(2019, 7, 4);
    order order_e(all, "Angelo", "Davis", "2698  Fairfax Drive, Parsippany, NJ", e);

    all.push_back(order_a);
    all.push_back(order_b);
    all.push_back(order_c);
    all.push_back(order_d);
    all.push_back(order_e);

    displayOrders();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    AddOrderDialog dialog;
    dialog.setModal(true);
    dialog.exec();

    displayOrders();
}

void MainWindow::on_pushButton_2_clicked()
{
    if (ui->tableWidget->selectionModel()->selectedRows().empty())
        return;

    size_t id = ui->tableWidget->item(ui->tableWidget->selectionModel()->selectedRows()[0].row(), 0)
            ->data(Qt::UserRole).value<size_t>();

    for (int i = 0; i < all.get_length(); i++)
        if (all[i].id == id)
        {
            all.remove(i);
            break;
        }

    displayOrders();
}

void MainWindow::on_pushButton_4_clicked()
{
    if (ui->tableWidget->selectionModel()->selectedRows().empty())
        return;

    size_t id = ui->tableWidget->item(ui->tableWidget->selectionModel()->selectedRows()[0].row(), 0)
            ->data(Qt::UserRole).value<size_t>();

    //order * tmp = get_order_by_id(all, id);
    //if (tmp->is_completed)
        //return;
    //tmp->is_completed = true;
    //tmp->completed = QDate::currentDate();

    for (int i = 0; i < all.get_length(); i++)
        if (all[i].id == id)
        {
            all[i].is_completed = true;
            all[i].completed = QDate::currentDate();
            break;
        }

    displayOrders();
}


void MainWindow::on_pushButton_3_clicked()
{
    for (int i = 0; i < all.get_length(); i++)
        if (all[i].is_completed == true)
        {
            all.remove(i);
            i--;
        }

    displayOrders();
}

void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    displayOrders();
}

void MainWindow::on_radioButton_2_clicked()
{
    displayOrders();
}

void MainWindow::on_radioButton_clicked()
{
    displayOrders();
}

void MainWindow::on_radioButton_3_clicked()
{
    displayOrders();
}

void MainWindow::on_tableWidget_itemSelectionChanged()
{
    if (ui->tableWidget->selectionModel()->selectedRows().empty())
    {
        ui->textBrowser->clear();
        return;
    }

    size_t id = ui->tableWidget->item(ui->tableWidget->selectionModel()->selectedRows()[0].row(), 0)
            ->data(Qt::UserRole).value<size_t>();

    order * tmp = get_order_by_id(all, id);

    ui->textBrowser->setText(tr("Order by %1 %2, whose address is: %3\nMade: %4\nCompleted: %5")
                             .arg(tmp->first_name).arg(tmp->last_name)
                             .arg(tmp->address.isEmpty() ? "-" : tmp->address)
                             .arg(tmp->added.toString("dd.MM.yyyy"))
                             .arg(tmp->is_completed ? tmp->completed.toString("dd.MM.yyyy"): "-"));
}
