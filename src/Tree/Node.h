// created by Michael 

// This is public, open source work created in 2018. 
// Michael Du and other contributors own all rights to this 
// work and intends to maintain it in confidence to preserve 
// this work. 

#ifndef Node_Interface
#define Node_Interface

#include<memory> 

namespace DS_VIS {

namespace TREE{ 


template<class data>
class Node{
private:
    data val;
    std::shared_ptr<Node<data>> left;    
    std::shared_ptr<Node<data>> right;
public:
    data getVal(){
        return val;
    }    

    std::shared_ptr<Node<data>> const & getLeft(){
        return left;
    }

    std::shared_ptr<Node<data>> const & getRight(){
        return right;
    }

    void setLeft(std::shared_ptr<Node<data>> node){
        left = node;
    }

    void setRight(std::shared_ptr<Node<data>> node)
    {
        right = node;
    }

};
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

} // TREE

} // DS_VIS
#endif
