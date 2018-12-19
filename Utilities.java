import java.util.*;
import java.math.*;

class Utilities {

    public static int GCD(int a, int b){
        while(b!=0) b ^= a ^= b ^= a %= b;
        return a;
    }
}
