/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *menuGroup;
    QPushButton *addNewDishButton;
    QPushButton *removeSelectedDishes;
    QTableWidget *dishesTable;
    QGroupBox *newOrderGroup;
    QPushButton *addDishesButton;
    QListWidget *currentOrder;
    QPushButton *removeDishesButton;
    QPushButton *pushButton_5;
    QSpinBox *tableNumSpin;
    QLabel *label;
    QSpinBox *quantitySpin;
    QGroupBox *allOrdersGroup;
    QListWidget *allOrdersListWidget;
    QComboBox *filter;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        menuGroup = new QGroupBox(centralwidget);
        menuGroup->setObjectName(QString::fromUtf8("menuGroup"));
        menuGroup->setGeometry(QRect(5, 5, 310, 590));
        addNewDishButton = new QPushButton(menuGroup);
        addNewDishButton->setObjectName(QString::fromUtf8("addNewDishButton"));
        addNewDishButton->setGeometry(QRect(0, 15, 140, 20));
        removeSelectedDishes = new QPushButton(menuGroup);
        removeSelectedDishes->setObjectName(QString::fromUtf8("removeSelectedDishes"));
        removeSelectedDishes->setGeometry(QRect(140, 15, 170, 20));
        dishesTable = new QTableWidget(menuGroup);
        if (dishesTable->columnCount() < 3)
            dishesTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        dishesTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        dishesTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        dishesTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        dishesTable->setObjectName(QString::fromUtf8("dishesTable"));
        dishesTable->setGeometry(QRect(0, 35, 310, 555));
        dishesTable->setFocusPolicy(Qt::NoFocus);
        dishesTable->setSortingEnabled(true);
        dishesTable->setColumnCount(3);
        newOrderGroup = new QGroupBox(centralwidget);
        newOrderGroup->setObjectName(QString::fromUtf8("newOrderGroup"));
        newOrderGroup->setGeometry(QRect(315, 5, 480, 200));
        addDishesButton = new QPushButton(newOrderGroup);
        addDishesButton->setObjectName(QString::fromUtf8("addDishesButton"));
        addDishesButton->setGeometry(QRect(380, 15, 71, 20));
        currentOrder = new QListWidget(newOrderGroup);
        currentOrder->setObjectName(QString::fromUtf8("currentOrder"));
        currentOrder->setGeometry(QRect(5, 15, 375, 185));
        currentOrder->setFocusPolicy(Qt::NoFocus);
        removeDishesButton = new QPushButton(newOrderGroup);
        removeDishesButton->setObjectName(QString::fromUtf8("removeDishesButton"));
        removeDishesButton->setGeometry(QRect(380, 35, 101, 23));
        pushButton_5 = new QPushButton(newOrderGroup);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(390, 160, 80, 30));
        tableNumSpin = new QSpinBox(newOrderGroup);
        tableNumSpin->setObjectName(QString::fromUtf8("tableNumSpin"));
        tableNumSpin->setGeometry(QRect(390, 80, 80, 20));
        tableNumSpin->setMinimum(1);
        tableNumSpin->setMaximum(60);
        label = new QLabel(newOrderGroup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(390, 60, 80, 20));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        quantitySpin = new QSpinBox(newOrderGroup);
        quantitySpin->setObjectName(QString::fromUtf8("quantitySpin"));
        quantitySpin->setGeometry(QRect(450, 15, 30, 20));
        quantitySpin->setMinimum(1);
        quantitySpin->setMaximum(9);
        allOrdersGroup = new QGroupBox(centralwidget);
        allOrdersGroup->setObjectName(QString::fromUtf8("allOrdersGroup"));
        allOrdersGroup->setGeometry(QRect(315, 205, 480, 390));
        allOrdersListWidget = new QListWidget(allOrdersGroup);
        allOrdersListWidget->setObjectName(QString::fromUtf8("allOrdersListWidget"));
        allOrdersListWidget->setGeometry(QRect(5, 40, 475, 350));
        allOrdersListWidget->setFocusPolicy(Qt::NoFocus);
        filter = new QComboBox(allOrdersGroup);
        filter->addItem(QString());
        filter->addItem(QString());
        filter->addItem(QString());
        filter->addItem(QString());
        filter->setObjectName(QString::fromUtf8("filter"));
        filter->setGeometry(QRect(5, 15, 100, 20));
        filter->setFocusPolicy(Qt::NoFocus);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        menuGroup->setTitle(QApplication::translate("MainWindow", "The Menu:", nullptr));
        addNewDishButton->setText(QApplication::translate("MainWindow", "Add new dish to the menu", nullptr));
        removeSelectedDishes->setText(QApplication::translate("MainWindow", "Remove selected from the menu", nullptr));
        QTableWidgetItem *___qtablewidgetitem = dishesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "name:", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = dishesTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "times ordered:", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = dishesTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "price:", nullptr));
        newOrderGroup->setTitle(QApplication::translate("MainWindow", "New order:", nullptr));
        addDishesButton->setText(QApplication::translate("MainWindow", "Add dish(es)", nullptr));
        removeDishesButton->setText(QApplication::translate("MainWindow", "Remove dish(es)", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "Make order", nullptr));
        label->setText(QApplication::translate("MainWindow", "Table number:", nullptr));
        allOrdersGroup->setTitle(QApplication::translate("MainWindow", "All orders:", nullptr));
        filter->setItemText(0, QApplication::translate("MainWindow", "Today", nullptr));
        filter->setItemText(1, QApplication::translate("MainWindow", "Last 7 days", nullptr));
        filter->setItemText(2, QApplication::translate("MainWindow", "Last 30 days", nullptr));
        filter->setItemText(3, QApplication::translate("MainWindow", "All time", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
