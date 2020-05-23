/********************************************************************************
** Form generated from reading UI file 'dishinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISHINFODIALOG_H
#define UI_DISHINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_dishInfoDialog
{
public:
    QLabel *label;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *dishInfoDialog)
    {
        if (dishInfoDialog->objectName().isEmpty())
            dishInfoDialog->setObjectName(QString::fromUtf8("dishInfoDialog"));
        dishInfoDialog->resize(480, 360);
        label = new QLabel(dishInfoDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 101, 16));
        textBrowser = new QTextBrowser(dishInfoDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 50, 461, 301));

        retranslateUi(dishInfoDialog);

        QMetaObject::connectSlotsByName(dishInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *dishInfoDialog)
    {
        dishInfoDialog->setWindowTitle(QApplication::translate("dishInfoDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("dishInfoDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dishInfoDialog: public Ui_dishInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISHINFODIALOG_H
