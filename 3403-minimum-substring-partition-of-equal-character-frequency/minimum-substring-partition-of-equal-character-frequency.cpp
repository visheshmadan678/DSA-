class Solution {
public:
    bool isValid(const vector<int>& freq, int length) {
        int target = -1;
        for (int count : freq) {
            if (count == 0) continue;
            if (target == -1) target = count;
            else if (count != target) return false;
        }
        return true;
    }

    int recursion(int idx, string &str, vector<int>&dp) {
        if (idx >= str.length()) return 0;
        if (dp[idx] != -1) return dp[idx];

        int take = 1e5;
        vector<int> freq(26, 0);
        for (int i = idx; i < str.length(); ++i) {
            freq[str[i] - 'a']++;
            int len = i - idx + 1;
            if (isValid(freq, len)) {
                take = min(take, 1 + recursion(i + 1, str, dp));
            }
        }
        return dp[idx] = take;
    }

    int minimumSubstringsInPartition(string s) {
        vector<int> dp(s.length(), -1);
        return recursion(0, s, dp);
    }
};
