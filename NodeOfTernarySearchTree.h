#ifndef NODEOFTERNARYSEARCHTREE_H
#define NODEOFTERNARYSEARCHTREE_H

/*!
 * \brief The NodeOfTernarySearchTree struct
 */
struct NodeOfTernarySearchTree
{
    NodeOfTernarySearchTree(char data, NodeOfTernarySearchTree* father):
        data(data), left(nullptr), right(nullptr), father(father)
    {}

    /*!
     * \brief dealockSubTree
     */
    void dealockSubTree()
    {
        if (left != nullptr)
        {
            left->dealockSubTree();
            delete left;
        }
        if (middle != nullptr)
        {
            middle->dealockSubTree();
            delete middle;
        }
        if (right != nullptr)
        {
            right->dealockSubTree();
            delete right;
        }
    }

    bool isTheLast = false;
    char data = '-';
    struct NodeOfTernarySearchTree* left = nullptr;
    struct NodeOfTernarySearchTree* middle = nullptr;
    struct NodeOfTernarySearchTree* right = nullptr;
    struct NodeOfTernarySearchTree* father = nullptr;
};

#endif // NODEOFTERNARYSEARCHTREE_H
