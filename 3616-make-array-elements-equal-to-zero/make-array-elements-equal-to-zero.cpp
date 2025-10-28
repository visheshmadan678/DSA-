class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        //so the question is all about the prefix sum may be 
        int n = nums.size(); int ans = 0;
        vector<int>prefix(n); vector<int>suffix(n);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];

        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i]; //calculate the prefix sum
        }

        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1] + nums[i];
        }

        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                int left_sum; int right_sum;

                if(i-1<0) left_sum = 0;
                else left_sum = prefix[i-1];

                if((i+1)>(n-1)) right_sum = 0;
                else right_sum = suffix[i+1];
                

                if(left_sum == right_sum) ans +=2;
                else if(abs(left_sum - right_sum) == 1) ans += 1;
                
            }
        }
        return ans;
    }
};