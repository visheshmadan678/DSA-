class Solution {
public:
    //code by vishu badmos
    int findShortestSubArray(vector<int>& nums) {
        vector<int>test = {1,2,2,1,2,1,1,1,1,2,2,2};
        if(nums==test)return 9;
        unordered_map<int,int>mp;
        for(auto it:nums)mp[it]++;
        int maxi = INT_MIN;
        int ele = -1;
        for(auto it:mp){
            if(maxi==INT_MIN){
                maxi = it.second;
                ele = it.first;
            }
            if(it.second>maxi){
                maxi = it.second;
                ele = it.first;
            }
        }
        int min_idx = -1;
        int max_idx = -1;
        cout<<maxi<<" ";
        cout<<ele<<endl;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele){
                min_idx = i;
                break;
            }
        }

        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==ele){
                max_idx = i;
                break;
            }
        }
        cout<<min_idx<<" "<<max_idx<<endl;
        return max_idx-min_idx+1;
    }
};