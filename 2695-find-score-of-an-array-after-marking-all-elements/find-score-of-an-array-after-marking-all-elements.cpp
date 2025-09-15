class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int,int>>vec;
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            mp[i] = nums[i]; // make a map for it
        }

        for(auto &it:mp){
            int idx = it.first;
            int ele = it.second;
            vec.push_back({ele,idx}); // push this into the vector 
        }

        sort(vec.begin(),vec.end());

        vector<int>visited(nums.size(),0);
        long long score = 0;
        for(auto &it:vec){
            //iterate through the vector now 
            int ele = it.first;
            int idx = it.second;
            if(!visited[idx]){
                score += ele; // update the score accordingly 
                if(idx+1<n)visited[idx+1] = 1;
                if(idx-1>=0)visited[idx-1] = 1; // mark as visited;
            }
        }
        return score;
    }
};