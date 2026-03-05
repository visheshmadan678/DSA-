class Solution {
public:
    int mod = 1e9 + 7;
    int countHomogenous(string s) {
        int left = 0, right = 0;
        int ans = 0;

        while(right < s.length()){
            while(right < s.length() && s[left] == s[right]){
                right++;
            }
            ans += (((right-left) * 1LL * (right-left+1)) / 2) % mod;
            left = right;
        }

        return ans % mod;
    }
};