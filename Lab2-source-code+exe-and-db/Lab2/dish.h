#ifndef DISH_H
#define DISH_H

#include <vector>
#include <time.h>

#include <QString>
#include <QStringList>
#include <QDataStream>

class dish
{
private:

    static size_t get_new_id_in_vector(std::vector<dish> dishes);

public:

    dish();
    dish(std::vector<dish> dishes, QString name, QStringList Description, double price);

    size_t id;

    QString name;
    QStringList description;

    double price;
    size_t popularity;

    bool is_on_the_menu;
};

inline QDataStream& operator << (QDataStream &out, const dish& d)
{
    out << d.id;
    out << d.name;
    out << d.price;
    out << d.popularity;
    out << d.description;
    out << d.is_on_the_menu;

    return out;
}

inline QDataStream& operator >> ( QDataStream &in, dish& d)
{
    in >> d.id;
    in >> d.name;
    in >> d.price;
    in >> d.popularity;
    in >> d.description;
    in >> d.is_on_the_menu;

    return in;
}

#endif // DISH_H
