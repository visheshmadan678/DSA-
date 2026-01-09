class Solution {
public:
    int dp[501][501];

    int solve(int i, int j, vector<int>& a, vector<int>& b) {
        if (i == a.size() || j == b.size())
            return INT_MIN;

        if (dp[i][j] != -1)
            return dp[i][j];

        int prod = a[i] * b[j];

        int takeBoth = prod + max(0, solve(i + 1, j + 1, a, b));
        int case1 = solve(i + 1, j, a, b);
        int case2 = solve(i, j + 1, a, b);

        return dp[i][j] = max({takeBoth, case1, case2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums1, nums2);
    }
};
