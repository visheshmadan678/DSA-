class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        unordered_map<long long, long long>mp;
        for(auto it:hours){
            int r = it%24;
            int needed = (24-r)%24;
            if(mp[needed]>0){
                ans += mp[needed];
            }
            mp[r]++;
        }
        return ans;
    }
};