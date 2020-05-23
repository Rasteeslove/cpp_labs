/********************************************************************************
** Form generated from reading UI file 'newdish.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDISH_H
#define UI_NEWDISH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewDish
{
public:
    QLineEdit *nameEdit;
    QTextEdit *descriptionEdit;
    QPushButton *addDishButton;
    QPushButton *cancelButton;
    QDoubleSpinBox *priceSpinBox;
    QLabel *label;

    void setupUi(QWidget *NewDish)
    {
        if (NewDish->objectName().isEmpty())
            NewDish->setObjectName(QString::fromUtf8("NewDish"));
        NewDish->resize(400, 400);
        nameEdit = new QLineEdit(NewDish);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(10, 10, 113, 20));
        descriptionEdit = new QTextEdit(NewDish);
        descriptionEdit->setObjectName(QString::fromUtf8("descriptionEdit"));
        descriptionEdit->setGeometry(QRect(10, 35, 380, 330));
        addDishButton = new QPushButton(NewDish);
        addDishButton->setObjectName(QString::fromUtf8("addDishButton"));
        addDishButton->setGeometry(QRect(235, 370, 75, 20));
        cancelButton = new QPushButton(NewDish);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(315, 370, 75, 20));
        priceSpinBox = new QDoubleSpinBox(NewDish);
        priceSpinBox->setObjectName(QString::fromUtf8("priceSpinBox"));
        priceSpinBox->setGeometry(QRect(50, 370, 80, 20));
        label = new QLabel(NewDish);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 370, 31, 21));

        retranslateUi(NewDish);

        QMetaObject::connectSlotsByName(NewDish);
    } // setupUi

    void retranslateUi(QWidget *NewDish)
    {
        NewDish->setWindowTitle(QApplication::translate("NewDish", "Add new dish to the menu", nullptr));
        nameEdit->setInputMask(QString());
        nameEdit->setPlaceholderText(QApplication::translate("NewDish", "Enter name", nullptr));
        descriptionEdit->setPlaceholderText(QApplication::translate("NewDish", "Enter description", nullptr));
        addDishButton->setText(QApplication::translate("NewDish", "Add dish", nullptr));
        cancelButton->setText(QApplication::translate("NewDish", "Cancel", nullptr));
        label->setText(QApplication::translate("NewDish", "Price:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewDish: public Ui_NewDish {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDISH_H
