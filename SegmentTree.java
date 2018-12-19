import java.util.*;


class SegmentTree {
    private static int sz, hei;

    private static boolean balance;

    private static ArrayList<Seg_Node> t;
    public SegmentTree(int N, int[] val){
//        sz = N;
        int S = 3*N;

        // Comon java, why do you need me to manually create this....get ur sh*t together
        for(int i = 0; i<S; ++i){
            t.add(new Seg_Node());
        }
    }



    private static void psUp(int idx){

        if(t.get(idx).getL()!=t.get(idx).getR()){
            t.get(idx).setGCD(Utilities.GCD(t.get(idx<<1).getGCD(),t.get(idx<<1|1).getGCD()));

            t.get(idx).setH(Math.max(t.get(idx<<1).getH(),t.get(idx<<1|1).getH()));

            t.get(idx).setMX(Math.max(t.get(idx<<1).getMX(),t.get(idx<<1|1).getMX()));

            t.get(idx).setMN(Math.max(t.get(idx<<1).getMN(),t.get(idx<<1|1).getMN()));

            t.get(idx).setH(Math.max(t.get(idx<<1).getH(),t.get(idx<<1|1).getH()));

            t.get(idx).setSz(t.get(idx<<1).getSz()+t.get(idx<<1|1).getSz()+1);

            t.get(idx).setBal(t.get(idx<<1).getBal()&& t.get(idx<<1|1).getBal()&&(Math.abs(t.get(idx<<1).getSz()-t.get(idx<<1|1).getSz())<=1));
        }

    }

    static void bld(int[] val, int idx, int l, int r){
        t.get(idx).setL(l);
        t.get(idx).setR(r);
        if(l==r){
//            t.get(idx).setVal(val[l]);
            t.set(idx, new Seg_Node(l,r,val[l],val[l],val[l],1,true));
            return;
        }

        int mid = l + (r - l)>>1;
        bld(val,idx<<1,l,mid);
        bld(val,idx<<1|1,mid+1,r);

        psUp(idx);
    }

    static void updI(int idx, int targ, int val){
        t.set(idx,new Seg_Node(t.get(idx).getL(),t.get(idx).getR(),0,0,0,t.get(idx).getH(),t.get(idx).getBal()));
        if(t.get(idx).getL()==t.get(idx).getR()&&t.get(idx).getL()==targ){
            t.get(idx).setGCD(val);
            t.get(idx).setMN(val);
            t.get(idx).setMX(val);
        }else{
            int mid = t.get(idx).getL() + (t.get(idx).getR() - t.get(idx).getL())>>1;
            if(targ<=mid)updI(idx<<1,targ,val);
            else updI(idx<<1|1,targ,val);
            psUp(idx);
        }
    }

    static int getSz() {
        return t.get(1).getSz();
    }

    static boolean getBal(){
        return balance;
    }

    static int getHei(){
        return hei;
    }

    
}


class BST{

}