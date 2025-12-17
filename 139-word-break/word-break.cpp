class Solution {
public:
    bool solve(int i, string &s,
               unordered_set<string>& dict,
               vector<int>& dp) {

        if (i == s.size())
            return true;

        if (dp[i] != -1)
            return dp[i];

        for (int j = i + 1; j <= s.size(); j++) {
            string word = s.substr(i, j - i);
            if (dict.count(word)) {
                if (solve(j, s, dict, dp))
                    return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);

        return solve(0, s, dict, dp);
    }
};
