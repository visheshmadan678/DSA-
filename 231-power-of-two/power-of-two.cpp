class Solution {
public:
    bool isPowerOfTwo(int n) {
        //code by vishu badmos 
        if(n==1)return true;
        if(n<0)return false; // return false straight away not a valid case
        int i=0;
        long long exp = pow(2,i);
        while(exp<n){
            i++;
            exp = pow(2,i);
        } 
        return exp == n;
    }
};