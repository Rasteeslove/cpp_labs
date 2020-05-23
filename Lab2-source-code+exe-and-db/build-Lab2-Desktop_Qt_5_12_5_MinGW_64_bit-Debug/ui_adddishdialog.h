/********************************************************************************
** Form generated from reading UI file 'adddishdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDISHDIALOG_H
#define UI_ADDDISHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_addDishDialog
{
public:
    QTextBrowser *descriptionEdit;
    QLabel *label;
    QLineEdit *nameEdit;
    QDoubleSpinBox *priceSpinBox;
    QPushButton *cancelButton;
    QPushButton *confirmButton;

    void setupUi(QDialog *addDishDialog)
    {
        if (addDishDialog->objectName().isEmpty())
            addDishDialog->setObjectName(QString::fromUtf8("addDishDialog"));
        addDishDialog->resize(320, 280);
        descriptionEdit = new QTextBrowser(addDishDialog);
        descriptionEdit->setObjectName(QString::fromUtf8("descriptionEdit"));
        descriptionEdit->setGeometry(QRect(10, 40, 300, 200));
        descriptionEdit->setReadOnly(false);
        label = new QLabel(addDishDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 250, 30, 20));
        nameEdit = new QLineEdit(addDishDialog);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(10, 10, 120, 20));
        priceSpinBox = new QDoubleSpinBox(addDishDialog);
        priceSpinBox->setObjectName(QString::fromUtf8("priceSpinBox"));
        priceSpinBox->setGeometry(QRect(40, 250, 60, 20));
        cancelButton = new QPushButton(addDishDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(235, 250, 75, 20));
        confirmButton = new QPushButton(addDishDialog);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(155, 250, 75, 20));

        retranslateUi(addDishDialog);

        QMetaObject::connectSlotsByName(addDishDialog);
    } // setupUi

    void retranslateUi(QDialog *addDishDialog)
    {
        addDishDialog->setWindowTitle(QApplication::translate("addDishDialog", "Add new dish to the menu", nullptr));
        descriptionEdit->setPlaceholderText(QApplication::translate("addDishDialog", "Enter description", nullptr));
        label->setText(QApplication::translate("addDishDialog", "Price:", nullptr));
        nameEdit->setPlaceholderText(QApplication::translate("addDishDialog", "Enter name", nullptr));
        cancelButton->setText(QApplication::translate("addDishDialog", "Cancel", nullptr));
        confirmButton->setText(QApplication::translate("addDishDialog", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addDishDialog: public Ui_addDishDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDISHDIALOG_H
