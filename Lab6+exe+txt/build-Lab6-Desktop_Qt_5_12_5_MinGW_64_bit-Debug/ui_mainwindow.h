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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTreeWidget *treeWidget;
    QListWidget *traversalResultListWidget;
    QPushButton *rmvItemButton;
    QPushButton *addButton;
    QTextEdit *whatToAddTextEdit;
    QLineEdit *searchEdit;
    QComboBox *traversalComboBox;
    QPushButton *loadCitiesButton;
    QLabel *searchResult;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        treeWidget = new QTreeWidget(centralwidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(230, 40, 560, 350));
        traversalResultListWidget = new QListWidget(centralwidget);
        traversalResultListWidget->setObjectName(QString::fromUtf8("traversalResultListWidget"));
        traversalResultListWidget->setGeometry(QRect(10, 170, 210, 220));
        rmvItemButton = new QPushButton(centralwidget);
        rmvItemButton->setObjectName(QString::fromUtf8("rmvItemButton"));
        rmvItemButton->setGeometry(QRect(700, 10, 90, 20));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(10, 10, 90, 20));
        whatToAddTextEdit = new QTextEdit(centralwidget);
        whatToAddTextEdit->setObjectName(QString::fromUtf8("whatToAddTextEdit"));
        whatToAddTextEdit->setGeometry(QRect(10, 40, 211, 91));
        searchEdit = new QLineEdit(centralwidget);
        searchEdit->setObjectName(QString::fromUtf8("searchEdit"));
        searchEdit->setGeometry(QRect(230, 10, 120, 20));
        traversalComboBox = new QComboBox(centralwidget);
        traversalComboBox->addItem(QString());
        traversalComboBox->addItem(QString());
        traversalComboBox->addItem(QString());
        traversalComboBox->addItem(QString());
        traversalComboBox->setObjectName(QString::fromUtf8("traversalComboBox"));
        traversalComboBox->setGeometry(QRect(10, 141, 120, 18));
        loadCitiesButton = new QPushButton(centralwidget);
        loadCitiesButton->setObjectName(QString::fromUtf8("loadCitiesButton"));
        loadCitiesButton->setGeometry(QRect(100, 10, 120, 20));
        searchResult = new QLabel(centralwidget);
        searchResult->setObjectName(QString::fromUtf8("searchResult"));
        searchResult->setGeometry(QRect(370, 10, 321, 20));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "string", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "key", nullptr));
        rmvItemButton->setText(QApplication::translate("MainWindow", "remove item", nullptr));
        addButton->setText(QApplication::translate("MainWindow", "add to tree", nullptr));
        searchEdit->setPlaceholderText(QApplication::translate("MainWindow", "search...", nullptr));
        traversalComboBox->setItemText(0, QApplication::translate("MainWindow", "NLR", nullptr));
        traversalComboBox->setItemText(1, QApplication::translate("MainWindow", "LNR", nullptr));
        traversalComboBox->setItemText(2, QApplication::translate("MainWindow", "RNL", nullptr));
        traversalComboBox->setItemText(3, QApplication::translate("MainWindow", "LRN", nullptr));

        loadCitiesButton->setText(QApplication::translate("MainWindow", "load cities' names", nullptr));
        searchResult->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
