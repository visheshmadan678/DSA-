class Solution {
public:
    bool isPowerOfTwo(int n) {
        //code by vishu badmos 
        if(n==1)return true;
        if(n<=0)return false; // return false straight away not a valid case
        double x = log2(n);
        return floor(x)==x && ceil(x)==x;
    }
};