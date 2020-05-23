#ifndef ORDER_H
#define ORDER_H

#include <QDate>
#include <QDataStream>
#include <QVector>

#include <vector>
#include "dish.h"

class order
{
public:

    order();

    order(const order&);

    std::vector<std::pair<size_t, size_t>> dishes;

    size_t table_num;
    double sum;

    QDate date;
};

inline QDataStream& operator << (QDataStream &out, const order& o)
{
    out << o.table_num;
    out << o.sum;
    out << o.date;

    QVector<size_t> qt_vector1;
    for (size_t i = 0; i < o.dishes.size(); i++)
        qt_vector1.push_back(o.dishes[i].first);
    out << qt_vector1;

    QVector<size_t> qt_vector2;
    for (size_t i = 0; i < o.dishes.size(); i++)
         qt_vector2.push_back(o.dishes[i].second);
    out << qt_vector2;

    return out;
}

inline QDataStream& operator >> ( QDataStream &in, order& o)
{
    in >> o.table_num;
    in >> o.sum;
    in >> o.date;

    QVector<size_t> qt_vector1;
    in >> qt_vector1;
    QVector<size_t> qt_vector2;
    in >> qt_vector2;

    for (int i = 0; i < qt_vector1.size(); i++)
        o.dishes.push_back(std::pair<size_t, size_t>(qt_vector1[i], qt_vector2[i]));

    return in;
}

#endif // ORDER_H
