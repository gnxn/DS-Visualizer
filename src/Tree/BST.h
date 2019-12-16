#include "Node.h"

#ifndef BST_Tree
#define BST_Tree

template<class data>
class BST{
private:
    int N;

    template<class dataType> 
    class BSTNode : public Node<dataType> {
    private: 
        int height;

        void setHeight(int H){
            height = H;
        }

    public: 
        int getHeight(){
            return height;
        }

    };

    std::shared_ptr<BSTNode<data>> root;

public:
    BST() : root{nullptr}{};

    std::shared_ptr<BSTNode<data>> bld(){
        root = nullptr;
    }

    int height(){
        return root->getHeight();
    }
};

#endif 