#ifndef ds_Vis_Tree
#define ds_Vis_Tree 

#include <vector> 

#include "Node.h"

namespace DS_VIS {

namespace TREE {

enum class infoType
{
    PreOrder,
    InOrder,
    PostOrder
};

template<class dataType>
class ITree {
private: 
    void preOrder(std::shared_ptr<dataType> node){
        
    } 

    void inOrder(std::shared_ptr<dataType> node){

    }

    void postOrder(std::shared_ptr<dataType> node){

    }
    
public: 
    virtual std::vector<dataType> getInfo(const infoType& info) = 0;
};

} // TREE

} // DS_VIS

#endif 