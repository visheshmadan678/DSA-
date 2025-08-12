class Solution {
public:
    static const int mod = 1e9 + 7;
int recursion(vector<int>&nums, int idx, int target, vector<vector<int>>&dp){
	if(target == 0)return 1;

    if(idx>=nums.size())return 0;
    
	if(idx==nums.size()-1){
		return nums[idx] == target;
	}

    if(dp[idx][target]!=-1)return dp[idx][target];

	 // straight away return zero as the output 

	int take = 0;

	if(nums[idx]<=target){
		take = (recursion(nums, idx+1,target - nums[idx],dp)) % mod;
	}

	int not_take = (recursion(nums,idx+1,target,dp)) % mod; // go with the same n 

	return dp[idx][target] = (take + not_take) % mod;
}
    int numberOfWays(int n, int x) {
        int i=1;
        
        vector<int>nums;
        
        while(pow(i,x)<=n){
            nums.push_back(pow(i,x));
            i++;
        }
        vector<vector<int>>dp(nums.size(),vector<int>(n+1,-1));
        return recursion(nums,0,n,dp);
    }
};