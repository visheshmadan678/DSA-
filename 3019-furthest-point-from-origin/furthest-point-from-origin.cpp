class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        unordered_map<char,int>mp;
        for(auto &it:moves){
            char ch = it;
            mp[ch]++;
        }

        int ans = INT_MIN;

        ans = max(mp['L'] + mp['_'] - mp['R'], mp['R'] + mp['_'] - mp['L']);
        return ans;
    }
};