class Solution {
public:
    int recursion(int idx, int prev, vector<int>&nums){
        if(idx>=nums.size())return 0;
        int take = 0;
        if(prev==-1001 || (nums[idx]-nums[idx-1])==prev){
            take = 1 + recursion(idx+1,nums[idx]-nums[idx-1],nums);
        }
        return take;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()<=2)return 0;
        int sum = 0;
        for(int i=0;i<=nums.size()-3;i++){
            sum += (1 + recursion(i+1,-1001,nums))-2;
        }
        return sum;
    }
};