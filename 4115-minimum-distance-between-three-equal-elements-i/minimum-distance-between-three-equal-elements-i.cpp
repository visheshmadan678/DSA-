class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
         
        // answer can still vary if the values are greater than 3 // so we need the closest three indices
        // it means we have to iterate through the whole array for the solution
        for(auto &it:mp){
            int ele = it.first;
            if(it.second.size() >= 3){
                for(int i=1;i < it.second.size()-1;i++){
                                    ans = min(ans,abs(it.second[i-1] - it.second[i]) + abs(it.second[i]- it.second[i+1]) + abs(it.second[i+1] - it.second[i-1]));
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};