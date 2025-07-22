class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0,right = 0,n = nums.size();
        unordered_map<int,int>mp;
        int sum = 0 , ans = INT_MIN;
        
        while(right<n){
            sum+= nums[right];
            mp[nums[right]]++;
            while(right-left+1>mp.size()){
                mp[nums[left]]--;
                sum -= nums[left];
                if(mp[nums[left]]==0)mp.erase(nums[left]);
                left++;
            }
            ans = max(ans,sum);
            right++;
        }

        return ans;
    }
};