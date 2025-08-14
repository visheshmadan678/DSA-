class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans;
        bool flag = false;
        for(int i=0;i<nums.size();i++){
            if(i!=nums[i] && flag==false){
                ans = nums[i];
                flag = true;
            }
            else if(i!=nums[i]){
                ans &= nums[i];
            }
        }
        return ans;
    }
};