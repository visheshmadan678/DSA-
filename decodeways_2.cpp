class Solution {
public:
    int mod = 1e9 + 7;
    int recursion(int idx, string& s, vector<int>&dp) {
        if (idx >= s.length())
            return 1;
        if(dp[idx]!=-1)return dp[idx];
        long long  take = 0;
        long long  take2 = 0;

        string str1 = s.substr(idx, 1); // of one length

        if (str1[0] == '0')
            return 0; // the edge case needs to be handled
        else if (str1[0] == '*') {
            for (int i = 1; i <= 9; i++) {
                take += recursion(idx + 1, s,dp) % mod;
            }
        } else
            take = recursion(idx + 1, s,dp) % mod;

        if (idx + 1 < s.length()) {
            string str2 = s.substr(idx, 2);
            // rest of the logic
            if (str2[0] == '*' && str2[1] == '*') {
                for (int i = 1; i <= 9; i++) {
                    for (int j = 1; j <= 9; j++) {
                        int num = i * 10 + j;
                        if (num <= 26) {
                            take2 += recursion(idx + 2, s,dp) % mod;
                        }
                    }
                }
            } else if (str2[0] == '*') {
                for (int i = 1; i <= 9; i++) {
                    string temp = "";
                    temp += i + '0';
                    temp += str2[1];
                    if (!temp.empty() && stoi(temp) <= 26) {
                        take2 += recursion(idx + 2, s,dp) % mod;
                    }
                }
            } else if (str2[1] == '*') {
                for (int i = 1; i <= 9; i++) {
                    string temp = "";
                    temp += str2[0];
                    temp += i + '0';
                    if (!temp.empty() && stoi(temp) <= 26) {
                        take2 += recursion(idx + 2, s,dp) % mod;
                    }
                }
            } else {
                // if none of them is star
                if (stoi(str2) <= 26)
                    take2 = recursion(idx + 2, s,dp) % mod;
            }
        }

        return dp[idx] = ((take % mod) + (take2 % mod)) % mod;
    }
    int numDecodings(string s) { 
        vector<int>dp(s.length(),-1);
        return recursion(0, s,dp) % mod; 
    }
};