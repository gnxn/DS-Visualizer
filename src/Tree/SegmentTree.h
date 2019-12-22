#include "Tree.h"

namespace DS_VIS {

namespace TREE {

template<class data> 
class SegmentTreeNode final : public Node<data> {
private:
    int l, r;
    data lazy;

public:    
    SegmentTreeNode (int l, int r) : l{l}, r{r}, lazy{false}{}

    int getL() {
        return l;
    }

    int getR() {
        return r;
    }
};

template<class data>
class SegmentTree final : public ITree<data> {

private: 
    std::shared_ptr<SegmentTreeNode<data>> root;

    void push_Down(std::shared_ptr<SegmentTreeNode<data>> root);

    void push_Up(std::shared_ptr<SegmentTreeNode<data>> root);

    void bld (
        std::shared_ptr<SegmentTreeNode<data>> root, 
        int l, 
        int r,
        const std::vector<data> & src
        );

    data query (std::shared_ptr<SegmentTreeNode<data>> root, int l, int r); 

public:

    SegmentTree(const std::vector<data> & src) : root {nullptr} {
        bld(root, 1, src.length(), src);
    }

    data qry(int l, int r) {
        query(root, l, r);
    }

}; 

} // TREE
} // DS_VIS
