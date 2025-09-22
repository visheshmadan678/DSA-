class Solution {
public:
    //code by vishu badmos
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &it:nums)mp[it]++; // insert into the map
        int maxi = INT_MIN;
        for(auto &it:mp)maxi = max(maxi,it.second); // find the maximum frequency
        int ans = 0;
        for(auto &it:mp)if(it.second==maxi)ans+=maxi;
        return ans;
    }
};