class Solution {
public:
    void window(int idx, string &s,int &ans){
        int right = idx;
        int size = s.length();
        vector<int>freq(26,0);

        while(right<size){
            freq[s[right] - 'a']++;
            int max_freq = INT_MIN;
            int min_freq = INT_MAX;
            for (int k = 0; k < 26; k++) {
                if (freq[k] > 0) { 
                    max_freq = max(max_freq, freq[k]);
                    min_freq = min(min_freq, freq[k]);
                }
            }
            ans += (max_freq - min_freq);
            right++;
        }
    }
    int beautySum(string s) {
        // i will go to every index and apply the sliding window all ca
        int ans = 0;
        int n = s.length();
        for(int i=0;i<n;i++)window(i,s,ans);
        return ans;
    }
};