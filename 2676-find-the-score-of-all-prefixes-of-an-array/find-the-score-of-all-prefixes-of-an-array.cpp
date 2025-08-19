class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long>ans(nums.size());
        int maxi = -1;
        for(int i=0;i<nums.size();i++){
            if(maxi==-1)maxi = nums[i];
            else maxi = max(maxi,nums[i]);
            ans[i] = maxi + nums[i];
        }
        long long sum = 0;
        for(int i=0;i<ans.size();i++){
            sum += ans[i];
            ans[i] = sum; 
        }
        return ans;
    }
};