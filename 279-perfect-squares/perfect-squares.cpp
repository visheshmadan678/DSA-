class Solution {
public:
    int recursion(int n,vector<int>&dp){
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        int take = 1e5; // taking it as maximum 
        for(int i=1;i*i<=n;i++){
            take = min(take, 1 + recursion(n-(i*i),dp));
        }
        return dp[n] = take;
    }
    int numSquares(int n) {
        if(sqrt(n)==floor(sqrt(n)))return 1; // if it is already a perfect square then there in not need to
        vector<int>dp(n+1,-1);
        //form the perfect squares 
        return recursion(n,dp);
    }
};