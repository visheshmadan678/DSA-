class Solution {
public:
    bool recursion(int n,vector<int>&dp){
        if(n==0)return 0;
        if(dp[n] != -1)return dp[n];

        for(int i=1; i*i <=n ;i++){
            bool take = recursion(n-(i*i),dp); // switching the player
            if(!take)
                return dp[n] = 1; // if in between alice won the match then immediately return that alice won
        }

        return dp[n] = 0;
    }
    bool winnerSquareGame(int n) {
        // if(n==1)return true;

        // double root = sqrt(n);

	    if(sqrt(n)==floor(sqrt(n)))return 1;

        vector<int>dp(n+1,-1);

        return recursion(n,dp);
    }
};