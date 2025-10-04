class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4)return 0; // as i can change the every element 
        sort(nums.begin(),nums.end()); 
        int case1  = abs(nums[0]-nums[nums.size()-4]);
        int case2 = abs(nums[3]-nums[nums.size()-1]);
        int case3 = abs(nums[2]-nums[nums.size()-2]);
        int case4 = abs(nums[nums.size()-3]-nums[1]);
        return min({case1,case2,case3,case4});
    }
};