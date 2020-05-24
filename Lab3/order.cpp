#include "order.h"

bool is_among(size_t id, d_list<order> group)
{
    for (int i = 0; i < group.get_length(); i++)
        if (group[i].id == id)
            return true;

    return false;
}

size_t order::get_unique_id(d_list<order> group)
{
    size_t new_id;

    do
    {
         new_id = (size_t)rand();
    } while (is_among(new_id, group));

    return new_id;
}

order::order()
{

}

order::order(d_list<order> group, QString fn, QString ln, QString address, QDate added)
{
    id = get_unique_id(group);

    first_name = fn;
    last_name = ln;
    this->address = address;
    this->added = added;

    is_completed = false;
}

