class Solution {
public:
    int minOperations(int k) {
        int n = k/2 + 1;
        int ops = INT_MAX;
        for(int i=2;i<=n;i++){
            int sub = i - 1; // is the starting operation
            int rem = (k-i) % i; // subtract that one number which i have already made 
            int div = ((k-i) / i);
            if(rem!=0){
                div++;
            }
            ops = min(ops,sub + div);
        }
        return ops==INT_MAX?0:ops;
    }
};