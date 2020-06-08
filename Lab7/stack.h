#ifndef STACK_H
#define STACK_H

#define DEF_SIZE 4

template <class Item> class Stack
{
private:

    int size;
    int capacity;
    Item * stack;

    void reallocate();

public:

    Stack();
    ~Stack();
    Stack(const Stack&);

    Stack& operator = (const Stack&);

    void push(Item);
    void pushWSortBU(Item);

    Item pop();
    Item peek();

    // index is counted from the top of the stack (0 is the upper item)
    bool rmv_at(unsigned int index);

    // index is counted from the bottom of the stack (size - 1 is the upper item)
    bool rev_rmv_at(unsigned int index);

    void rmv_in_range(Item from, Item to);

    int getSize();
    bool isEmpty();

};

template <class Item> Stack<Item>::Stack()
{
    capacity = DEF_SIZE;
    stack = new Item[capacity];
    size = 0;
}

template <class Item> Stack<Item>::~Stack()
{
    delete[] stack;
}

template <class Item> Stack<Item>::Stack(const Stack &other)
{
    this->stack = new Item[other.capacity];
    for (int i = 0; i < other.size; i++)
        this->stack[i] = other.stack[i];

    this->size = other.size;
    this->capacity = other.capacity;
}

template <class Item> void Stack<Item>::reallocate()
{
    Item * reallocated = new Item[size == capacity ? (capacity *= 2) : (capacity /= 2)];

    for (int i = 0; i < size; i++)
    {
        reallocated[i] = stack[i];
    }

    delete[] stack;

    stack = reallocated;
}

template <class Item> void Stack<Item>::push(Item newItem)
{
    stack[size++] = newItem;

    if (size == capacity)
    {
        reallocate();
    }
}

template <class Item> void Stack<Item>::pushWSortBU(Item newItem)
{
    Stack<Item> tmp;

    while (!this->isEmpty() && this->peek() > newItem)
        tmp.push(this->pop());

    this->push(newItem);

    while (!tmp.isEmpty())
        this->push(tmp.pop());
}

template <class Item> Item Stack<Item>::pop()
{
    return stack[--size];
}

template <class Item> Item Stack<Item>::peek()
{
    return stack[size - 1];
}

template <class Item> int Stack<Item>::getSize()
{
    return size;
}

template <class Item> bool Stack<Item>::isEmpty()
{
    return size == 0;
}

template <class Item> Stack<Item>& Stack<Item>::operator = (const Stack& other)
{
    delete[] this->stack;

    this->stack = new Item[other.capacity];
    for (int i = 0; i < other.size; i++)
        this->stack[i] = other.stack[i];

    this->size = other.size;
    this->capacity = other.capacity;

    return *this;
}

template <class Item> bool Stack<Item>::rmv_at(unsigned int index)
{
    if (index >= size)
        return false;

    Stack<Item> tmp;
    for (int i = 0; i < index; i++)
        tmp.push(this->pop());

    this->pop();

    while (!tmp.isEmpty())
        this->push(tmp.pop());

    return true;
}

template <class Item> bool Stack<Item>::rev_rmv_at(unsigned int index)
{
    return rmv_at(size - 1 - index);
}

template <class Item> void Stack<Item>::rmv_in_range(Item from, Item to)
{
    if (from > to)
        return;

    Stack<Item> tmp;

    while (!this->isEmpty() && this->peek() > to)
        tmp.push(this->pop());

    while (!this->isEmpty() && this->peek() >= from)
        this->pop();

    while (!tmp.isEmpty())
        this->push(tmp.pop());
}

#endif // STACK_H
