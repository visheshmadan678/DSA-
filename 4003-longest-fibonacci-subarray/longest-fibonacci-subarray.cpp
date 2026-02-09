class Solution {
public:
    int dp[100001];

    int recursion(int idx, int next_idx, vector<int>& nums) {
        if (idx == nums.size())
            return 0;
        // if (dp[idx] != -1)
        //     return dp[idx];

        int ans = 0;
        if (next_idx+1 < nums.size() &&
            (nums[idx] + nums[next_idx]) == nums[next_idx + 1]) {
            ans = 1 + recursion(next_idx, next_idx + 1, nums);
        }
        return ans;
    }
    int longestSubarray(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int ans = INT_MIN;
        for (int i = 0; i < nums.size() - 1; i++) {
            ans = max(ans, 2 + recursion(i, i + 1, nums));
        }

        return ans;
    }
};