#include "BST.h"

using namespace std;

template<class data>
shared_ptr<BSTNode<data>> BST<data>::addNode (
        std::shared_ptr<BSTNode<data>> node, 
        data val)
{
    if(!node){
        node = shared_ptr<data>(new BSTNode<data>(val));
    }

    if(val < node->getVal()){
        node.setLeft(addNode(node->getLeft(), val));
    } else if (val > node->getVal()){
        node.setRight(addNode(node->getRight(), val));
    }

    return node;
}

template<class data>
shared_ptr<BSTNode<data>> removeNode(
    shared_ptr<BSTNode<data>> node,
    data val)
{
    if (!node) {
        return node;
    }

    if (node->getVal() > val) {
        node->setLeft(removeNode(node->getLeft(), val));
    } else if (node->getVal() < val) {
        node->setRight(removeNode(node->getRight(), val));
    } else {
        if (node->getLeft() == nullptr && node->getRight() == nullptr){
            node = nullptr;
        } else if (node->getLeft() == nullptr) {
            auto left = node->getLeft();
            return left;
        } else if (node->getRight() == nullptr) {
            auto right = node->getRight();
            return right;
        } else {
            auto nxt = node->getRight();
            shared_ptr<BSTNode<data>> parent = nullptr;

            while (nxt->getLeft()){
                parent = nxt;
                nxt = nxt->getLeft();
            }

            node = nxt;

            if (parent) {
                parent->setLeft(nxt->getRight());
            } else {
                node->setRight(nxt->getRight());
            }
        }
    }
    
    return node;
}


