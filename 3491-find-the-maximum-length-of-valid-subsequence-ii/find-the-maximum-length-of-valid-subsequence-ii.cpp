class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>>dp(k,vector<int>(nums.size(),1)); // initializing the base as 1
        int ans = 1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                int mod = (nums[i]+nums[j])%k;
                dp[mod][i] = max(dp[mod][i],1+dp[mod][j]);
                ans = max(ans,dp[mod][i]);
            }
        }
        return ans;
    }
};