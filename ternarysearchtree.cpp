#include "ternarysearchtree.h"
#include <iostream>
#include <sstream> //for std::stringstream

TernarySearchTree::TernarySearchTree()
{

}

TernarySearchTree::~TernarySearchTree()
{
    if (root != nullptr)
    {
        root->dealockSubTree();
        delete root;
    }
}

bool TernarySearchTree::insert(const std::string& data)
{
    NodeOfTernarySearchTree*  last = nullptr; //to avoid go on

    NodeOfTernarySearchTree*  tmp = root;
    std::string currentData = data;
    bool inserted = false;
    bool canInsertInTheMiddleCreatingNode = true;

    int newAlocations = 0;
    bool finalWasSet = false;

    while (currentData.length() > 0)
    {
        char c = currentData.front();
        currentData.erase(currentData.begin()+0);
        canInsertInTheMiddleCreatingNode = true;

        //tmp é o proprio nó a ser checado
        if (tmp == nullptr) //root é nullptr
        {
            NodeOfTernarySearchTree*  node = new NodeOfTernarySearchTree(c, nullptr);
            root = node;
            tmp = root;
            newAlocations++;

            last = node;

            if (currentData.length() == 0)
            {
                if (tmp->isTheLast == false)
                {
                    tmp->isTheLast = true;
                    finalWasSet = true;
                }
            }
        }
        else
        {
            inserted = false;
            while (inserted == false)
            {
                if (tmp->data == c && tmp != last)
                {
                    if (currentData.length() == 0)
                    {
                        if (tmp->isTheLast == false)
                        {
                            tmp->isTheLast = true;
                            finalWasSet = true;
                        }
                    }

                    last = tmp;

                    //considera como inserido e vai para o proximo
                    if (tmp->middle != nullptr)
                        tmp = tmp->middle;

                    inserted = true; //mark as inserted
                }
                else if (tmp->middle == nullptr && canInsertInTheMiddleCreatingNode)
                {
                    tmp->middle = new NodeOfTernarySearchTree(c, tmp);
                    tmp = tmp->middle;
                    newAlocations++;

                    last = tmp;

                    if (currentData.length() == 0)
                    {
                        if (tmp->isTheLast == false)
                        {
                            tmp->isTheLast = true;
                            finalWasSet = true;
                        }
                    }
                    inserted = true; //mark as inserted
                }
                else if (c > tmp->data)
                {
                    if (tmp->right == nullptr)
                    {
                        NodeOfTernarySearchTree*  node = new NodeOfTernarySearchTree(c, tmp);
                        tmp->right = node;
                        tmp = tmp->right;
                        newAlocations++;

                        last = tmp;

                        if (currentData.length() == 0)
                        {
                            if (tmp->isTheLast == false)
                            {
                                tmp->isTheLast = true;
                                finalWasSet = true;
                            }
                        }

                        inserted = true; //mark as inserted
                    }
                    else
                    {
                        tmp = tmp->right;
                        canInsertInTheMiddleCreatingNode = false;
                    }
                }
                else //(c < tmp->data)
                {
                    if (tmp->left == nullptr)
                    {
                        NodeOfTernarySearchTree*  node = new NodeOfTernarySearchTree(c, tmp);
                        tmp->left = node;
                        tmp = tmp->left;
                        newAlocations++;

                        last = tmp;

                        if (currentData.length() == 0)
                        {
                            if (tmp->isTheLast == false)
                            {
                                tmp->isTheLast = true;
                                finalWasSet = true;
                            }
                        }

                        inserted = true; //mark as inserted
                    }
                    else
                    {
                        tmp = tmp->left;
                        canInsertInTheMiddleCreatingNode = false;
                    }
                }
            }
        }
    }

    return data.length() > 0 && (newAlocations > 0 || finalWasSet);
}

NodeOfTernarySearchTree*  TernarySearchTree::search(const std::string& data)
{
    std::string currentData = data;
    NodeOfTernarySearchTree*  tmp = root;
    bool pending = false;
    while (currentData.size() > 0)
    {
        char c = currentData.front();
        currentData.erase(currentData.begin()+0);

        pending = true;
        while (pending)
        {
            if (tmp == nullptr)
            {
                return nullptr;
            }
            else if (tmp->data == c)
            {
                if (currentData.size() == 0)
                {
                    return tmp->isTheLast? tmp: nullptr;
                }

                //move on
                tmp = tmp->middle; //sendo null ou não
                pending = false;
            }
            //não é o do meio
            else if (c > tmp->data)
            {
                if (tmp->right == nullptr)
                {
                    //Não existe
                    return nullptr;
                }
                else
                {
                    tmp = tmp->right;
                }
            }
            else if (c < tmp->data)
            {
                if (tmp->left == nullptr)
                {
                    //Não existe
                    return nullptr;
                }
                else
                {
                    tmp = tmp->left;
                }
            }
        }
    }

    return nullptr;//lets see
}

bool TernarySearchTree::remove(const std::string& data)
{
    NodeOfTernarySearchTree*  node = search(data);
    if (node == nullptr)
        return false;

    node->isTheLast = false;

    NodeOfTernarySearchTree*  tmp = node;
    while (tmp != nullptr &&
           tmp->middle == nullptr &&
           tmp->isTheLast == false)
    {
        NodeOfTernarySearchTree*  backup = tmp;
        tmp = tmp->father;

        if (tmp != nullptr)
        {
            clearChildPointer(tmp, backup);
            organizeNode(tmp);
        }
        else //(tmp == nullptr)
        {
            root = nullptr;
            delete backup;
        }
    }

    return true;
}

void TernarySearchTree::organizeNode(NodeOfTernarySearchTree*  node)
{
    NodeOfTernarySearchTree*  father = node->father;

    if (node->middle != nullptr || node->isTheLast)
        return; //has nothing to do

    NodeOfTernarySearchTree*  left = node->left;
    NodeOfTernarySearchTree*  right = node->right;

    if (left == nullptr && right == nullptr)
        return;

    if (left == nullptr)
    {
        replacePointerInfather
        (
            father,
            node,
            right
        );
    }
    else if (right == nullptr)
    {
        replacePointerInfather
        (
            father,
            node,
            left
        );
    }
    //left e right são diferente de null
    else if (right->left == nullptr)
    {
        //right é o novo nó
        replacePointerInfather
        (
            father,
            node,
            right
        );

        //o left é o seu filho esquerdo
        right->left = left;
        left->father = right;
    }
    else if (left->right == nullptr)
    {
        //right é o novo nó
        replacePointerInfather
        (
            father,
            node,
            left
        );

        left->right = right;
        right->father = left;
    }
}

void TernarySearchTree::replacePointerInfather
(
    NodeOfTernarySearchTree*  node,
    NodeOfTernarySearchTree*  toBeReplaced,
    NodeOfTernarySearchTree*  toReplaceNew
)
{
    if (node != nullptr)
    {
        if (node->left == toBeReplaced)
        {
            node->left = toReplaceNew;
            toReplaceNew->father = node;
        }
        else if (node->middle == toBeReplaced)
        {
            node->middle = toReplaceNew;
            toReplaceNew->father = node;
        }
        else if (node->right == toBeReplaced)
        {
            node->right = toReplaceNew;
            toReplaceNew->father = node;
        }
    }
    else
    {
        root = toReplaceNew;
        toReplaceNew->father = nullptr;
    }
}

void TernarySearchTree::clearChildPointer
(
    NodeOfTernarySearchTree*  node,
    NodeOfTernarySearchTree*  toClear
)
{
    if (node->left == toClear)
    {
        node->left = nullptr;
    }
    else if (node->middle == toClear)
    {
        node->middle = nullptr;
    }
    else if (node->right == toClear)
    {
        node->right = nullptr;
    }

    delete toClear;
}

int TernarySearchTree::getChildCount(NodeOfTernarySearchTree*  node)
{
    int sum = 0;
    if (node->left != nullptr)
        sum++;
    if (node->middle != nullptr)
        sum++;
    if (node->right != nullptr)
        sum++;
    return sum;
}

const std::string TernarySearchTree::getPointerAsString(NodeOfTernarySearchTree*  node)
{
    const void * address = static_cast<const void*>(node);
    std::stringstream ss;
    ss << address;
    std::string name = ss.str();
    return "\""+name+"\"";
}

const std::string TernarySearchTree::getDrawOfNode(NodeOfTernarySearchTree*n)
{
    std::string code;
    code += getPointerAsString(n)+" ";
    code += "[label=\"{ {"+std::string(1, n->data);
    std::string middle = (n->isTheLast? "1":"0");
    code += "|"+middle+"} |";
    code += "{ <left> left| <equal> equal| <right> right} }\"];";
    return code;
}

const std::string TernarySearchTree::getDotFile()
{
    std::string textToFile = "digraph g{";
    textToFile += "Root[shape=none fontcolor=blue];";
    textToFile += "node [shape=record];";

    if (root == nullptr)
    {
        textToFile += "NULL [ fontcolor=red ];Root -> NULL;";
    }
    else
    {
        textToFile += "Root->"+getPointerAsString(root)+";";
        int count = 0;
        exibirSubArvore(root, textToFile, count);
    }

    textToFile += "}";

    return textToFile;
}

NodeOfTernarySearchTree *TernarySearchTree::getRoot()
{
    return this->root;
}

void TernarySearchTree::exibirSubArvore
(
    struct NodeOfTernarySearchTree*  n,
    std::string& content,
    int &count
)
{
    //Desenha o dado do nó n
    content += getDrawOfNode(n);

    if (n->left == nullptr)
    {
        content += getPointerAsString(n)+"->NULL"+std::to_string(count++)+" [label=\"left\"];";
    }
    else
    {
        content += getPointerAsString(n)+"->"+getPointerAsString(n->left)+"  [label=\"left\"];";
        exibirSubArvore
        (
            n->left,
            content,
            count
        );
    }

    if (n->middle == nullptr)
    {
        content += getPointerAsString(n)+"->NULL"+std::to_string(count++)+"   [label=\"middle\"];";
    }
    else
    {
        content += getPointerAsString(n)+"->"+getPointerAsString(n->middle)+"   [label=\"middle\"];";
        exibirSubArvore
        (
            n->middle,
            content,
            count
        );
    }

    if (n->right == nullptr)
    {
        content += getPointerAsString(n)+"->NULL"+std::to_string(count++)+"   [label=\"right\"];";
    }
    else
    {
        content += getPointerAsString(n)+"->"+getPointerAsString(n->right)+"   [label=\"right\"];";
        exibirSubArvore
        (
            n->right,
            content,
            count
        );
    }
}

