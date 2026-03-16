class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        unordered_map<int,pair<int,int>> mp3;

        for(auto &it:nums1){
            mp1[it]++;
        }

        for(auto &it:nums2){
            mp2[it]++;
        }

       
        for(auto &it:mp1){
            int ele = it.first;
            int freq1 = it.second;
            int freq2 = mp2[ele];
            mp3[ele] = {freq1,freq2};
        }

        for(auto &it:mp2){
            int ele = it.first;
            int freq2 = it.second;
            int freq1 = mp1[ele];

            if(mp3.find(ele) == mp3.end()){
                mp3[ele] = {freq1,freq2};
            }
        }

        int ans = 0;

        for(auto &it:mp3){
            int a = it.second.first;
            int b = it.second.second;

            if((a + b) % 2 != 0) return -1;

            ans += abs(a - b) / 2;
        }

        return ans / 2;
    }
};