import java.util.ArrayList;

class BST{
    private static BST_Nodes t;

//    private static int val;

    BST(int N, int[] val){
        bld(val);
    }

    void bld(int[] vals){
        for (int val : vals) {
            t = insert(val,t);
        }
    }

    BST_Nodes insert(int val, BST_Nodes rt){
        if(rt == null){
            return new BST_Nodes(val);
        }
        if(rt.getVal() == val){
            return rt;
        }
        if(rt.getVal() < val){
            t.setR(insert(val,t.getR()));
        }
        else t.setL(insert(val,t.getL()));

        return t;
    }

    void del(int val, BST_Nodes rt){

    }

    void del(int val){
        
    }

    int minK(){
        BST_Nodes rt = t;
        while(rt.getL()!=null){
            rt = rt.getL();
        }
        return rt.getVal();
    }
}