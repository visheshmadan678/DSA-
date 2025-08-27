class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<long long , long long>mp;
        long long count = 0;
        for(auto it:nums2)mp[it*k]++; // add the value mutliply by k into the map 

        for(auto it:nums1){
            int ele = it;
            if(ele%k!=0)continue;
            else{
                for(int f = 1; f*f <= ele; f++){
                    if(ele%f!=0){
                        continue;
                        //then continue
                    }
                    int f1 = f; int f2 = ele/f1;
                    count += mp[f1];
                    if(f1!=f2)count += mp[f2];
                }
            }
        }
        return count;
    }
};