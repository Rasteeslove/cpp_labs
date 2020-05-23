#include "dish.h"

bool is_among(std::vector<dish> dishes, size_t new_id)
{
    for (size_t i = 0; i < dishes.size(); i++)
        if (new_id == dishes[i].id)
            return true;

    return false;
}

size_t dish::get_new_id_in_vector(std::vector<dish> dishes)
{
    size_t new_id = 0;

    do
        new_id = rand();
    while (is_among(dishes, new_id) || new_id == 0);

    return new_id;
}

dish::dish()
{

}

dish::dish(std::vector<dish> dishes, QString name, QStringList description, double price)
{
    id = get_new_id_in_vector(dishes);
    this->name = name;
    this->description = description;
    this->price = price;

    popularity = 0;
    is_on_the_menu = true;
}
