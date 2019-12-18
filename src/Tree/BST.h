
#ifndef BST_Tree
#define BST_Tree

#include <algorithm>
#include <vector>
#include "Node.h"

template<class dataType> 
class BSTNode : public Node<dataType> {
private: 
    int height;

    bool isBalanced;

    void setHeight(int H){
        height = H;
    }

    

public:
    int getHeight()
    {
        return height;
    }

    bool balanced()
    {
        return isBalanced;
    }

    void setBalanced()
    {
        int left = this->getLeft() ? this->getLeft->getHeight() : 0;
        int right = this->getRight() ? this->getRight->getHeight() : 0;
        isBalanced = std::abs(left - right) <= 1;
    }

    BSTNode() : height{1},
                isBalanced{false}
    {}

};

template<class data>
class BST {
private:
    int N;

    std::shared_ptr<BSTNode<data>> root;

    std::shared_ptr<BSTNode<data>> addNode(
        std::shared_ptr<BSTNode<data>> node,
        data val);

    std::shared_ptr<BSTNode<data>> removeNode(
        std::shared_ptr<BSTNode<data>> node,
        data val);

public:
    BST() : root{nullptr} {};
 

    std::shared_ptr<BSTNode<data>> bld()
    {
        root = nullptr;
    }

    int height()
    {
        return root->getHeight();
    }

    void remove(data val)
    {
        root = removeNode(root, val);
    }   

    void insert(const data &val)
    {
        root = addNode(root, val);
    }

    void remove(const data &val)
    {
        root = removeNode(root, val);
    }
};

#endif 