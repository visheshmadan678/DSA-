class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       vector<int>dp(nums.size(),1);
       vector<int>parent(nums.size(),-1);
       sort(nums.begin(),nums.end());
       int lis = 0;
       int lisindex = 0;
       for(int i=0;i<nums.size();i++){
            for(int j=0;j<=i-1;j++){
                if(nums[i]%nums[j]==0){
                    //if they both are not equal 
                  if(dp[i]<dp[j]+1){
                        dp[i] = dp[j]+1;
                        parent[i] = j;
                  }
                  if(lis<dp[i]){
                    lis = dp[i];
                    lisindex = i;
                  }
                }
            }
       }
      

       vector<int>ans;
       while(lisindex!=-1){
            ans.push_back(nums[lisindex]);
            lisindex = parent[lisindex];
       }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};