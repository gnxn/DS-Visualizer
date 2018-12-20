class node{
    private static int l, r;

//    private static int val;
    node(int l, int r){
        this.l = l;
        this.r = r;
//        this.val = val;
    }
    node(){
        this.l = 0;
        this.r = 0;
//        this.val = 0;
    }

    int getL(){
        return this.l;
    }

    void setL(int val){
        this.l = val;
    }

    int getR(){
        return this.r;
    }

    void setR(int val){
        this.r = val;
    }

//    int getVal(){
//        return this.val;
//    }

//    void setVal(int val){
//        this.val = val;
//    }
}


class Seg_Node extends node{
    private static int MN, MX, GCD; // possible operations

    private static int sz;

    private static int h; // height

    private static boolean bal;
    Seg_Node(int l, int r, int mx, int mn, int gcd, int H, boolean b) {
        super(l, r);
        MN = mn;
        MX = mx;
        GCD = gcd;
        h = H;
        bal = b;
    }
    Seg_Node(){
        super();
    }

    void setMN(int x){
        MN = x;
    }

    void setGCD(int x){
        GCD = x;
    }

    void setMX(int x){
        MX = x;
    }

    void setH(int x){
        h = x;
    }

    void setSz(int x){sz = x;}

    void setBal(boolean x){bal = x;}

    int getMN(){return MN;}

    int getMX(){return MX;}

    int getGCD(){return GCD;}

    int getH(){return h;}

    int getSz(){return sz;}

    boolean getBal(){return bal;}
}


class BST_Nodes {
    private static int val;

    private static boolean bal;

    private static int h;

    private static int sz;

    private static BST_Nodes l,r;

    BST_Nodes(int v){
//        super(l,r);
//        super();
        val = v;
        l = null;
        r = null;
    }

    BST_Nodes(int v, BST_Nodes l1, BST_Nodes r1){
        val = v;
        l = l1;
        r = r1;
    }

    void setH(int x){
        h = x;
    }

    void setSz(int x){sz = x;}

    void setBal(boolean x){bal = x;}

    void setVal(int x){val = x;}

    void setL(BST_Nodes l1){
        l = l1;
    }

    void setR(BST_Nodes r1){
        r = r1;
    }

    int getH(){return h;}

    int getSz(){return sz;}

    boolean getBal(){return bal;}

    int getVal(){return val;}

    BST_Nodes getL(){
        return l;
    }

    BST_Nodes getR(){
        return r;
    }
}
