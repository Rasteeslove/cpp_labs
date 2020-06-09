#ifndef BTREE_H
#define BTREE_H

#include <vector>

#include <QString>
#include <QStringList>
#include <QTreeWidget>

template <class Item> class bTree
{

private:

    struct node
    {
        unsigned int key;
        Item data;
        node * left;
        node * right;

        node(Item data, unsigned int key);
        node(const node &other);
    };

    node * root;

    void delete_subtree_of_root(node * n);
    int count_children(node * n);
    node * form_tree(node * root, std::vector<std::pair<QString, unsigned int>> list);
    node * copy_nodes(const node * root);
    QTreeWidgetItem * display_nodes(node * n, QTreeWidgetItem * twi);

    void build_nlr(node * n, QStringList &list);
    void build_lnr(node * n, QStringList &list);
    void build_rnl(node * n, QStringList &list);
    void build_lrn(node * n, QStringList &list);

    node * get_node_by_key(node * root, int key);

public:

    bTree();
    bTree(QStringList str_list);
    bTree(const bTree &other);

    ~bTree();

    bTree& operator = (const bTree &other);

    void insert(Item new_item);
    void insert(QStringList list);
    void removeItemWKey(int key);
    void displayInTreeWidget(QTreeWidget * tw);

    QStringList toQStrListNLR();
    QStringList toQStrListLNR();
    QStringList toQStrListRNL();
    QStringList toQStrListLRN();

    QString getItemWKey(int key);

};

template <class Item> bTree<Item>::node::node(Item data, unsigned int key)
{
    this->data = data;
    this->key = key;
    this->left = this->right = nullptr;
}

template <class Item> void bTree<Item>::delete_subtree_of_root(node * n)
{
    if (n != nullptr)
    {
        delete_subtree_of_root(n->left);
        delete_subtree_of_root(n->right);
        delete n;
    }
}

template <class Item> bTree<Item>::bTree()
{
    this->root = nullptr;
}

template <class Item> bTree<Item>::node::node(const node &other)
{
    this->key = other.key;
    this->data = other.data;
    this->left = this->right = nullptr;
}

template <class Item> typename bTree<Item>::node * bTree<Item>::copy_nodes(const node * root)
{
    if (root == nullptr)
        return nullptr;

    node * new_one = new node(*root);

    new_one->left = copy_nodes(root->left);
    new_one->right = copy_nodes(root->right);

    return new_one;
}

template <class Item> bTree<Item>::bTree(const bTree &other)
{
    this->root = copy_nodes(other.root);
}

template <class Item> bTree<Item>& bTree<Item>::operator = (const bTree &other)
{
    delete_subtree_of_root(this->root);
    this->root = copy_nodes(other.root);

    return *this;
}

template <class Item> typename bTree<Item>::node * bTree<Item>::form_tree(node * root,
                                                                        std::vector<std::pair<QString, unsigned int>> list)
{
    if (list.empty())
    {
        return nullptr;
    }
    unsigned int separator = list.size() / 2;

    root = new node(list[separator].first, list[separator].second);
    list.erase(list.begin() + separator);

    std::vector<std::pair<QString, unsigned int>> left(list.begin(), list.begin() + separator);
    std::vector<std::pair<QString, unsigned int>> right(list.begin() + separator, list.end());

    root->left = form_tree(root->left, left);
    root->right = form_tree(root->right, right);

    return root;
}

template <class Item> typename bTree<Item>::node * bTree<Item>::get_node_by_key(node * root, int key)
{
    if (root == nullptr)
        return nullptr;

    if (root->key == key)
        return root;

    if (root->key > key)
        return get_node_by_key(root->left, key);
    else
        return get_node_by_key(root->right, key);
}

template <class Item> int bTree<Item>::count_children(node * n)
{
    if (n == nullptr)
        return 0;

    return 1 + count_children(n->left) + count_children(n->right);
}

template <class Item> bTree<Item>::bTree(QStringList str_list)
{
    str_list.removeAll(QString(""));

    if (str_list.empty())
    {
        this->root = nullptr;
    }

    str_list.sort();
    std::vector<std::pair<QString, unsigned int>> list;
    for (int i = 0; i < str_list.length(); i++)
        list.push_back(std::pair<QString, unsigned int>(str_list[i], i));

    this->root = form_tree(this->root, list);
}

template <class Item> bTree<Item>::~bTree()
{
    delete_subtree_of_root(this->root);
}

template <class Item> void bTree<Item>::removeItemWKey(int key)
{
    node * to_remove = get_node_by_key(this->root, key);

    if (to_remove == nullptr || to_remove == this->root)
        return;

    to_remove->data = nullptr;

    bTree<Item> new_tree(this->toQStrListLNR());
    *this = new_tree;
}

template <class Item> QString bTree<Item>::getItemWKey(int key)
{
    node * item = get_node_by_key(this->root, key);

    if (item == nullptr)
        return "not found";

    return "key: " + QString::number(key) + "; string: " + item->data +
            "; num of children: " + QString::number(count_children(item) - 1);
}

// functions for insertion and resetting of the the

template <class Item> void bTree<Item>::insert(Item new_item)
{
    if (this->root == nullptr)
    {
        this->root = new node(new_item, 0);
        return;
    }

    QStringList tree_list = this->toQStrListLNR();

    int index = 0;
    while (index < tree_list.size() - 1 && new_item > tree_list[index])
        index++;

    tree_list.insert(index, new_item);
    bTree<Item> new_tree(tree_list);
    *this = new_tree;
}
template <class Item> void bTree<Item>::insert(QStringList list)
{
    if (this->root == nullptr)
    {
        bTree<Item> new_tree(list);
        *this = new_tree;
        return;
    }

    QStringList tree_list = this->toQStrListLNR();
    tree_list.append(list);
    tree_list.sort();

    bTree<Item> new_tree(tree_list);
    *this = new_tree;
}

// traversals via QStringLists - meaning they work for bTree<QString> only
// [another way would be to use std::vector / custom list class for filling them while traversing]

template <class Item> void bTree<Item>::build_nlr(node * n, QStringList &list)
{
    if (n == nullptr)
        return;

    list.append(n->data);
    build_nlr(n->left, list);
    build_nlr(n->right, list);
}
template <class Item> QStringList bTree<Item>::toQStrListNLR()
{
    QStringList list;
    build_nlr(this->root, list);
    return list;
}

template <class Item> void bTree<Item>::build_lnr(node * n, QStringList &list)
{
    if (n == nullptr)
        return;

    build_lnr(n->left, list);
    list.append(n->data);
    build_lnr(n->right, list);
}
template <class Item> QStringList bTree<Item>::toQStrListLNR()
{
    QStringList list;
    build_lnr(this->root, list);
    return list;
}

template <class Item> void bTree<Item>::build_rnl(node * n, QStringList &list)
{
    if (n == nullptr)
        return;

    build_rnl(n->right, list);
    list.append(n->data);
    build_rnl(n->left, list);
}
template <class Item> QStringList bTree<Item>::toQStrListRNL()
{
    QStringList list;
    build_rnl(this->root, list);
    return list;
}

template <class Item> void bTree<Item>::build_lrn(node * n, QStringList &list)
{
    if (n == nullptr)
        return;

    build_lrn(n->left, list);
    build_lrn(n->right, list);
    list.append(n->data);
}
template <class Item> QStringList bTree<Item>::toQStrListLRN()
{
    QStringList list;
    build_lrn(this->root, list);
    return list;
}

// display in QTreeWidget functions

template <class Item> void bTree<Item>::displayInTreeWidget(QTreeWidget * tw)
{
    QTreeWidgetItem * root = new QTreeWidgetItem();
    tw->addTopLevelItem(display_nodes(this->root, root));
}
template <class Item> QTreeWidgetItem* bTree<Item>::display_nodes(node * n, QTreeWidgetItem * twi)
{
    twi->setText(0, QString::number(n->key));
    twi->setData(0, Qt::UserRole, n->key);
    twi->setText(1, n->data);

    if (n->left != nullptr)
    {
        QTreeWidgetItem * left = new QTreeWidgetItem();
        twi->addChild(display_nodes(n->left, left));
    }
    if (n->right != nullptr)
    {
        QTreeWidgetItem * right = new QTreeWidgetItem();
        twi->addChild(display_nodes(n->right, right));
    }

    return twi;
}

#endif // BTREE_H
