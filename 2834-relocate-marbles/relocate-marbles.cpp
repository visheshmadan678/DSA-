class Solution {
public:
    //code by vishu badmos
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        //let's go for the second approach 
        unordered_map<int,int>mp;
        for(auto it:nums)mp[it]++; // include the elements into the map

        for(int i=0;i<moveFrom.size();i++){
            int a = moveFrom[i];
            int b = moveTo[i]; 
            mp.erase(a);
            mp[b] = 1;
        }

        vector<int>ans;
        for(auto it:mp){
            ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());

        return ans;
    }
};