class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = 0;
        long long sum = 0;
        int n = nums.size();
        int ans = INT_MIN;
        while(right<n){
            sum += nums[right];
            while((long long)(right-left+1)*nums[right]-sum>k){
                sum -= nums[left];
                left++;
            }
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};