#ifndef TABLEWIDGETNUMBERITEM_H
#define TABLEWIDGETNUMBERITEM_H

#include <QString>
#include <QTableWidgetItem>

class TableWidgetNumberItem : public QTableWidgetItem
{

public:

    TableWidgetNumberItem(QString number) :
        QTableWidgetItem(number) { }

    bool operator < (const QTableWidgetItem &other) const
    {
        return text().toDouble() < other.text().toDouble();
    }

};

#endif // TABLEWIDGETNUMBERITEM_H
