class Solution {
public: 
    //code by vishu badmos
    int dp[31][1001]; // define the dp array 
    int mod = 1e9 + 7;
    int recursion(int dice, int target, int k){
        if(target==0){
            return dice==0; // return if all the dices have been used or not to form that target
        }
        if(dice<=0 || target<0)return 0;

        if(dp[dice][target]!=-1)return dp[dice][target];

        int take = 0;
        for(int i=1;i<=k;i++){
            if(i<=target){
                take = (take + recursion(dice-1,target-i,k)) % mod;
            }
        }

        return dp[dice][target] = take; // return the take as well 
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp)); // set the values of the dp array as -1
        return recursion(n,target,k);
    }
};