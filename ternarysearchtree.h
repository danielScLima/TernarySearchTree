#ifndef TERNARY_SEARCH_TREE_H
#define TERNARY_SEARCH_TREE_H

#include <iostream>
#include "NodeOfTernarySearchTree.h"

/*!
 * \brief The TernarySearchTree class
 */
class TernarySearchTree
{
public:
    /*!
     * \brief TernarySearchTree
     */
    TernarySearchTree();

    ~TernarySearchTree();

    /*!
     * \brief insert
     * \param data
     */
    bool insert(const std::string& data);

    /*!
     * \brief remove
     * \param data
     * \return
     */
    bool remove(const std::string& data);

    /*!
     * \brief search
     * \param data
     * \return
     */
    NodeOfTernarySearchTree* search(const std::string& data);

    /*!
     * \brief getDotFile
     * \return
     */
    const std::string getDotFile();

    /*!
     * \brief getRoot
     * \return
     */
    NodeOfTernarySearchTree* getRoot();
private:
    struct NodeOfTernarySearchTree* root = nullptr;

    /*!
     * \brief exibirSubArvore
     * \param n
     * \param content
     * \param count
     */
    void exibirSubArvore
    (
        NodeOfTernarySearchTree*n,
        std::string &content,
        int &count
    );

    /*!
     * \brief getDrawOfNode
     * \param n
     * \return
     */
    const std::string getDrawOfNode(NodeOfTernarySearchTree*n);

    /*!
     * \brief getPointerAsString
     * \param node
     * \return
     */
    const std::string getPointerAsString(NodeOfTernarySearchTree*node);

    /*!
     * \brief getChildCount
     * \param node
     * \return
     */
    int getChildCount(NodeOfTernarySearchTree*node);

    /*!
     * \brief clearChildPointer
     * \param node
     * \param toClear
     */
    void clearChildPointer
    (
        NodeOfTernarySearchTree* node,
        NodeOfTernarySearchTree* toClear
    );

    /*!
     * \brief organizeNode
     * \param node
     */
    void organizeNode(NodeOfTernarySearchTree* node);

    /*!
     * \brief replacePointerInfather
     * \param node
     * \param toBeReplaced
     * \param toReplaceNew
     */
    void replacePointerInfather
    (
        NodeOfTernarySearchTree* node,
        NodeOfTernarySearchTree* toBeReplaced,
        NodeOfTernarySearchTree* toReplaceNew
    );
};

#endif // TERNARY_SEARCH_TREE_H
