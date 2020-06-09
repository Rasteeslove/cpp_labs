#include <QFile>
#include <QMessageBox>
#include <QTextStream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "btree.h"

bTree<QString> main_tree;

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

void MainWindow::displayTree()
{
    ui->treeWidget->clear();

    main_tree.displayInTreeWidget(ui->treeWidget);
}

void MainWindow::on_loadCitiesButton_clicked()
{
    QStringList strings;

    QFile inputFile("cities.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
          strings.push_back(in.readLine());

       inputFile.close();
    }

    ui->whatToAddTextEdit->setText(strings.join("\n"));
}

void MainWindow::on_addButton_clicked()
{
    QString str = ui->whatToAddTextEdit->toPlainText();
    QStringList strList = str.split(QRegExp("[\n]"),QString::SkipEmptyParts);

    if (strList.empty())
        return;

    main_tree.insert(strList);
    displayTree();
}

void MainWindow::on_traversalComboBox_currentIndexChanged(int index)
{
    ui->traversalResultListWidget->clear();
    switch (index)
    {
    case 0:
    {
        ui->traversalResultListWidget->addItems(main_tree.toQStrListNLR());
        break;
    }
    case 1:
    {
        ui->traversalResultListWidget->addItems(main_tree.toQStrListLNR());
        break;
    }
    case 2:
    {
        ui->traversalResultListWidget->addItems(main_tree.toQStrListRNL());
        break;
    }
    case 3:
    {
        ui->traversalResultListWidget->addItems(main_tree.toQStrListLRN());
        break;
    }
    }
}

void MainWindow::on_rmvItemButton_clicked()
{
    QList<QTreeWidgetItem*> selected = ui->treeWidget->selectedItems();
    if (selected.empty())
        return;

    QTreeWidgetItem * to_remove = selected[0];
    int index = to_remove->data(0, Qt::UserRole).value<int>();

    main_tree.removeItemWKey(index);
    displayTree();
}

void MainWindow::on_searchEdit_cursorPositionChanged(int arg1, int arg2)
{
    bool convertable;
    int key = ui->searchEdit->text().toInt(&convertable);

    if (convertable)
        ui->searchResult->setText(main_tree.getItemWKey(key));
    else
        ui->searchResult->setText("invalid input");
}
