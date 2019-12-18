// created by Michael 

// This is public, open source work created in 2018. 
// Michael Du and other contributors own all rights to this 
// work and intends to maintain it in confidence to preserve 
// this work. 

#ifndef Node_Interface
#define Node_Interface

#include<memory> 

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

#endif
