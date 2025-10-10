class Solution {
public:
    int recursion(int idx, vector<int>& nums, int jump, vector<int>& dp) {
        if (idx >= nums.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int take = nums[idx] + recursion(idx + jump, nums, jump, dp);
        return dp[idx] = take;
    }
    int maximumEnergy(vector<int>&nums, int k) {
        vector<int> dp(nums.size(), -1);
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, recursion(i, nums, k, dp));
        }
        return ans;
    }
};