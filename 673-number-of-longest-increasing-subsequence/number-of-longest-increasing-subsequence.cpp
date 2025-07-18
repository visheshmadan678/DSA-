class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> cnt(nums.size(), 1);
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                        ans = max(ans, dp[i]);
                    } else if (dp[j] + 1 == dp[i]) {
                        // if they both becomes equal
                        cnt[i] += cnt[j];
                    } // stored the lis
                }
            }
        }
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (dp[i] == ans)
                total += cnt[i];
        }
        return total;
    }
};