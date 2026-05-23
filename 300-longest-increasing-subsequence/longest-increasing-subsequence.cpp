class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1); // initially everyone is having one 
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] > nums[i]){
                    dp[j] = max(dp[j],1 + dp[i]);
                }
            }
        }

        int ans = INT_MIN;
        for(auto &it:dp){
            ans = max(ans,it);
        }
        return ans;
    }
};