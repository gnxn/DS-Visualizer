#ifndef BST_Tree
#define BST_Tree

#include <algorithm>
#include <vector>

#include "Tree.h"

namespace DS_VIS {

namespace TREE {

template<class data>
class BST final : public ITree<data> {
private:
    std::shared_ptr<BSTNode<data>> root;

    std::shared_ptr<BSTNode<data>> addNode(
        std::shared_ptr<BSTNode<data>> node,
        data val);

    std::shared_ptr<BSTNode<data>> removeNode(
        std::shared_ptr<BSTNode<data>> node,
        data val);

public:
    BST(): root{nullptr}{};
 

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

    std::vector<data> getInfo(const infoType& info) {

        std::vector<data> info_arry;

        if (info == infoType::PreOrder)
        {
            info_arry = preOrder(root);
        }
        if (info == infoType::InOrder)
        {
            info_arry = inOrder(root);
        }
        if (info == infoType::PostOrder)
        {
            info_arry = postOrder(root);
        }

        return info_arry;
    }
};

} // TREE

} // DS_VIS
#endif 