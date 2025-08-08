#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int OFFSET = 500; // shift diffs to positive indices
    int dp[1005][1005]; // dp[idx][diffShift]
    vector<int> nums;
    int n;

    int recursion(int idx, int diff) {
        int diffShift = diff + OFFSET;
        if (dp[idx][diffShift] != -1) return dp[idx][diffShift];

        int best = 0; // at least the current element
        for (int next = idx + 1; next < n; next++) {
            if (nums[next] - nums[idx] == diff) {
                best = max(best, 1 + recursion(next, diff));
            }
        }
        return dp[idx][diffShift] = best;
    }

    int longestArithSeqLength(vector<int>& arr) {
        nums = arr;
        n = nums.size();
        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = nums[j] - nums[i];
                ans = max(ans, 2 + recursion(j, diff)); // 2 elements: i and j
            }
        }
        return ans;
    }
};
