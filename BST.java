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

    BST_Nodes del(int val, BST_Nodes rt){
         if(rt==null)return null;
         if(val==rt.getVal()){
             if(rt.getL()==null&&rt.getR()==null)return null;
             else // non-leaf nodes, get the min of the right subtree as the new root
             {
                 int M = minK(rt.getR());
                 rt = new BST_Nodes(M, rt.getL(), del(M,rt.getR()));
             }
         }
         if(val<rt.getVal()){
             rt.setL(del(val,rt.getL()));
         }
         else rt.setR(del(val,rt.getR()));
         return rt;
    }

    void del(int val){
        del(val,t);
    }

    int minK(BST_Nodes rt){
//        BST_Nodes rt = t;
        while(rt.getL()!=null){
            rt = rt.getL();
        }
        return rt.getVal();
    }
}