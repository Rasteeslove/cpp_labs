#ifndef D_LIST_H
#define D_LIST_H

#include <QString>
#include <QStringList>

template <class Item> class d_list
{
private:

    struct node
    {
    public:

        node * prev;
        Item data;
        node * next;

        node();
        node(Item data);

    };

    node * head;
    node * tail;
    int length;

    bool is_index_valid(int index);
    node * get_node(int index);

public:

    int get_length() { return length; }
    bool is_empty() { return length == 0; }

    d_list();
    d_list(const d_list &other);
    d_list(const QStringList &other);

    ~d_list();

    Item& operator [](int index);
    void insert(Item new_item, int index);
    void merge(d_list &new_sublist, int index);
    void remove(int index);

    void push_back(Item new_item);
    void push_forward(Item new_item);

};

template <class Item> bool d_list<Item>::is_index_valid(int index)
{
    if (index < 0 || index >= this->length)
        return false;

    return true;
}

template <class Item> d_list<Item>::node::node(Item data)
{
    this->prev = this->next = nullptr;
    this->data = data;
}

template <class Item> d_list<Item>::d_list()
{
    head = tail = nullptr;
    length = 0;
}

template <class Item> d_list<Item>::~d_list()
{
    node * current_node = head;

    for (int i = 0; i < length; i++)
    {
        node * tmp = current_node->next;
        delete current_node;
        current_node = tmp;
    }

}

template <class Item> d_list<Item>::d_list(const d_list &other)
{
    head = tail = nullptr;
    length = 0;

    for (int i = 0; i < other.get_length(); i++)
        push_back(other[i]);
}

template <class Item> d_list<Item>::d_list(const QStringList &other)
{
    head = tail = nullptr;
    length = 0;

    for (int i = 0; i < other.length(); i++)
        push_back(other[i]);
}

template <class Item> void d_list<Item>::insert(Item new_item, int index)
{
    if (index != -1 && !is_index_valid(index))
    {
        throw std::out_of_range("invalid index error");
    }

    node * new_node = new node(new_item);

    // adding as the new head
    if (index == -1)
    {
        if (head != nullptr)
            head->prev = new_node;

        new_node->next = head;
        head = new_node;

        if (tail == nullptr)
            tail = head;

        length++;
        return;
    }

    // getting node at index position [ node after which the new node's gonna be ]
    node * location = this->get_node(index);
    node * tmp = location->next;

    // connecting new node to list
    new_node->prev = location;
    new_node->next = tmp;

    // connecting list to new node
    location->next = new_node;
    if (tmp != nullptr)
        tmp->prev = new_node;
    else
        tail = new_node;

    length++;
}

template <class Item> void d_list<Item>::push_back(Item new_item)
{
    insert(new_item, this->length - 1);
}

template <class Item> void d_list<Item>::push_forward(Item new_item)
{
    insert(new_item, -1);
}

template <class Item> void d_list<Item>::remove(int index)
{
    node * redundant = this->get_node(index);

    // reconfiguring list ptr-s
    if (redundant == head)
        head = redundant->next;
    if (redundant == tail)
        tail = redundant->prev;

    // relinking list
    if (redundant->prev != nullptr)
        redundant->prev->next = redundant->next;
    if (redundant->next != nullptr)
        redundant->next->prev = redundant->prev;

    delete redundant;
    length--;
}

template <class Item> Item& d_list<Item>::operator [](int index)
{
    return get_node(index)->data;
}

template <class Item> void d_list<Item>::merge(d_list &new_sublist, int index)
{
    if (index != -1 && !is_index_valid(index))
    {
        throw std::out_of_range("invalid index error");
    }
    if (new_sublist.is_empty())
        return;

    if (this->is_empty())
    {
        this->head = new_sublist.head;
        this->tail = new_sublist.tail;
    }
    else
        if (index == -1)
        {
            head->prev = new_sublist.tail;
            new_sublist.tail->next = head;
            head = new_sublist.head;
        }
        else
        {
            node * location = get_node(index);
            node * tmp = location->next;

            new_sublist.head->prev = location;
            new_sublist.tail->next = tmp;

            location->next = new_sublist.head;
            if (tmp != nullptr)
                tmp->prev = new_sublist.tail;
            else
                tail = new_sublist.tail;
        }

    length += new_sublist.length;

    new_sublist.head = new_sublist.tail = nullptr;
    new_sublist.length = 0;
}

template <class Item> struct d_list<Item>::node * d_list<Item>::get_node(int index)
{
    if (!is_index_valid(index))
    {
        throw std::out_of_range("invalid index error");
    }

    node * current_node;

    if (index < length / 2)
    {
        current_node = head;
        for (int i = 0; i < index; i++)
            current_node = current_node->next;
    }
    else
    {
        current_node = tail;
        for (int i = this->length - 1; i > index; i--)
            current_node = current_node->prev;
    }

    return current_node;
}

#endif // D_LIST_H
