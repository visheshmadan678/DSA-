class Solution {
public:
    long long dp[1005][3][505];
    long long recursion(int index,int state,int k, vector<int>&prices){
        //these are the base cases for this
        if (index == prices.size()) {
            if (state == 0) return 0;
            return INT_MIN; // cannot end while holding position
        }

        if (k == 0) {
            if (state == 0) return 0;
            return INT_MIN; // no transactions left to close position
        }

        if(dp[index][state][k] != -1)return dp[index][state][k];

        long long val = 0;
        if(state == 0){
            //it means i can start a new transaction
            // new transaction can be any of it either the normal of short selling
            val = max({-prices[index] + recursion(index+1,1,k,prices), recursion(index+1,0,k,prices),prices[index] + recursion(index+1,2,k,prices)});
                       // ek normal kari                               //kuch bhi nahi kiya            // ya fir short selling wali kari
        }
        else if(state == 1){
            //it means in past i have done some normal transaction
            val = max(prices[index] + recursion(index+1,0,k-1,prices), recursion(index+1,1,k,prices));
        }
        else if(state == 2){
            //it means in past i have done some short selling transaction
            val = max(-prices[index] + recursion(index+1,0,k-1,prices), recursion(index+1,2,k,prices));
        }

        return dp[index][state][k] = val; // in the end return value
    }
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp,-1,sizeof(dp));
        return recursion(0,0,k,prices);
    }
};