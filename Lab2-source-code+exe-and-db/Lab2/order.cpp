#include "order.h"

order::order()
{
    sum = 0;
}

order::order(const order &other)
{
    this->sum = other.sum;
    this->date = other.date;
    this->dishes = other.dishes;
    this->table_num = other.table_num;
}
