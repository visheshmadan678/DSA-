class Solution {
public:
    long long dp[101][101][101];
    long long recursion(int idx1, int idx2, vector<int>& nums1, vector<int>& nums2,
                  int k) {

        if (k == 0)
            return 0;

        if (idx1 >= nums1.size() || idx2 >= nums2.size())
            return LLONG_MIN;

        if (dp[idx1][idx2][k] != -1e16)
            return dp[idx1][idx2][k];
        long long ans = LLONG_MIN;

        if (nums1.size() - idx1 >=k || nums2.size() - idx2 >= k) {

            long long pick = recursion(idx1 + 1, idx2 + 1, nums1, nums2, k - 1);

            if (pick != LLONG_MIN) 
                ans = 1LL * nums1[idx1] * nums2[idx2] + pick;
        }

        ans = max(ans, recursion(idx1 + 1, idx2, nums1, nums2, k));
        ans = max(ans, recursion(idx1, idx2 + 1, nums1, nums2, k));

        return dp[idx1][idx2][k] = ans;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                for(int k=0;k<101;k++){
                    dp[i][j][k] = -1e16;
                }
            }
        }
        return recursion(0,0,nums1,nums2,k);
    }
};