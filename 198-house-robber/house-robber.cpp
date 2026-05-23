class Solution {
public:
    int rob(vector<int>& nums) {
        //so dp[i] be a state which denotes that this is the maximum amount of money till now which we have robbed
        // how do we determine the value of dp[i] ? we cannot rob the house which is just previous to us but we can rob the house previous to it which at i - 2 th index 
        // at every index i have choice that do i have to rob it or not ? may be i am not robbing it right now ?also so that i can rob i - 1 th index 
        vector<int>dp(nums.size());
        if(nums.size() <= 2){
            if(nums.size() == 1){
                return nums[0];
            }
            else{
                int ans = max(nums[0],nums[1]);
                return ans;
            }   
        }
        dp[0] = nums[0]; dp[1] = nums[1];
        // dp[i] = max(dp[i-1],dp[i-2] + cost[i]);

        for(int i = 2; i < nums.size(); i++){
            if(i == 2)dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
            else dp[i] = nums[i] + max(dp[i-2],dp[i-3]);
        }

        int ans = *max_element(dp.begin(),dp.end());

        return ans;
    }
};