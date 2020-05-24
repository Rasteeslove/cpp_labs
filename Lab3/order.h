#ifndef ORDER_H
#define ORDER_H

#include <time.h>

#include <QString>
#include <QDate>

#include "d_list.h"

class order
{
private:

    static size_t get_unique_id(d_list<order> group);

public:

    order();
    order(d_list<order> group, QString fn, QString ln, QString address, QDate added);

    size_t id;
    bool is_completed;

    QString first_name;
    QString last_name;

    QString address;

    QDate added;
    QDate completed;

};

extern d_list<order> all;

#endif // ORDER_H
