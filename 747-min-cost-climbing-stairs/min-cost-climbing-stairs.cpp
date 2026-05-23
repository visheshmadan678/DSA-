class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // state dp[i] is state which will tell me the minimum cost till this index 
        // how will dp[i] will depend on the previous states ? 
        // either i can come from the i - 1 index or i can come from the i - 2 the index 

        vector<int>dp(cost.size() + 2);
        dp[0] = cost[0]; dp[1] = cost[1];

        for(int i = 2; i <= cost.size() + 1; i++){
            if(i < cost.size())dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
            else dp[i] = min(dp[i-1],dp[i-2]);
        }

        return dp[cost.size()];
    }
};