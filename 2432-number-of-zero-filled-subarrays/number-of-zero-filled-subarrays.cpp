class Solution {
public:
    //code by vishu badmos 
    long long zeroFilledSubarray(vector<int>& nums) {
        long long right = 0, n = nums.size();
        long long left = 0;
        long long ans = 0;
        while(right<n){
            bool flag = false;
            int left = -1;
            while(right < n && nums[right]==0){
                if(!flag && left==-1){
                    flag = true;
                    left = right; // store the first occurence
                }
                right++;
            }
            
            if(flag)ans += ((1LL*right-left)*1LL*(right-left+1))/2;

            right++;
        }
        return ans;
    }
};