#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>

#include <QString>

#include <stdexcept>
#include "stack.h"

template <class Item>
class hashTable
{
private:

    unsigned int m;
    Stack<Item> * array;

    unsigned int modulus_hash_function(unsigned int value)
    {
        return value % m;
    }

    // must return index < m, otherwise out of range error
    unsigned int hash_function(int value)
    {
        if (value < 0)
            value = -value;

        return modulus_hash_function(value);
    }

public:

    unsigned int capacity() { return m; }

    unsigned int size()
    {
        unsigned int size = 0;

        for (unsigned int i = 0; i < m; i++)
            if (!array[i].isEmpty())
                size++;

        return size;
    }

    unsigned int height()
    {
        unsigned int output = 0;
        for (unsigned int i = 0; i < m; i++)
            if (this->array[i].getSize() > output)
                output = this->array[i].getSize();

        return output;
    }

    hashTable(unsigned int size = 499)
    {
        m = size;
        array = new Stack<Item>[m];
    }

    ~hashTable()
    {
        delete[] array;
    }

    // return false if the collision happens, adds int anyway tho
    bool addNumber(int number)
    {
        unsigned int index = hash_function(number);
        bool is_there_no_collisions = true;

        if (!array[index].isEmpty())
            is_there_no_collisions = false;

        array[index].pushWSortBU(number);

        return is_there_no_collisions;
    }

    Stack<Item> getStackAtIndex(unsigned int index)
    {
        return array[index];
    }

    Stack<Item> * getStackPtrAtIndex(unsigned int index)
    {
        return &array[index];
    }

    // just checking w/o any action
    bool tryGetUpperItemAtIndex(unsigned int index)
    {
        return !getStackAtIndex(index).isEmpty();
    }

    Item getUpperItemAtIndex(unsigned int index)
    {
        Stack<Item> at_index = getStackAtIndex(index);

        if (at_index.isEmpty())
        {
            throw std::runtime_error("Empty stack error. Should have used tryGetUpperItemAtIndex prior to this.");
        }

        return at_index.peek();
    }

    Item grabUpperItemAtIndex(unsigned int index)
    {
        Stack<Item> at_index = getStackAtIndex(index);

        if (at_index.isEmpty())
        {
            throw std::runtime_error("Empty stack error. Should have used tryGetUpperItemAtIndex prior to this.");
        }

        return at_index.pop();
    }

    // get coordinate <array_index, stack_index>; if not found, returns <m, 0> as a non-existent index
    std::pair<unsigned int, unsigned int> searchForInt(int num)
    {
        std::pair<unsigned int, unsigned int> result(m, 0);
        unsigned int array_index = hash_function(num);

        Stack<Item> tmp;
        for (unsigned int stack_index = 0; tryGetUpperItemAtIndex(array_index); stack_index++)
        {
            Item upper = grabUpperItemAtIndex(array_index);
            tmp.push(upper);
            if (upper == num)
            {
                result = std::pair<unsigned int, unsigned int>(array_index, stack_index);
                break;
            }
        }

        while (!tmp.isEmpty())
        {
            array[array_index].push(tmp.pop());
        }

        return result;
    }

    std::vector<std::pair<Stack<Item>, unsigned int>> toStdVector()
    {
        std::vector<std::pair<Stack<Item>, unsigned int>> output;
        for (unsigned int i = 0; i < this->capacity(); i++)
            if (!this->array[i].isEmpty())
                output.push_back(std::pair<Stack<Item>, unsigned int>(this->array[i], i));

        return output;
    }

    void rmv_items_in_range(int from, int to)
    {
        if (from > to)
            return;

        for (int i = 0; i < m; i++)
            array[i].rmv_in_range(from, to);
    }

};

#endif // HASHTABLE_H
