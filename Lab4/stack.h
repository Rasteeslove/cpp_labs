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
    Item pop();
    Item peek();

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


#endif // STACK_H
