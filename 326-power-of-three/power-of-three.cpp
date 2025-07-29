class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
        int i=0;
        long long temp  = pow(3,i);
        while(temp<n){
            i++;
            temp = pow(3,i);
        }

        return temp==n;
    }
};