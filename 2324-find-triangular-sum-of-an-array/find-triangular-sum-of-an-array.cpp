class Solution {
public:
    int triangularSum(vector<int>& nums) {
        //its same as the pascal triangle brother
        while(nums.size()!=1){
            vector<int>temp;
            for(int i=0;i<nums.size()-1;i++){
                temp.push_back((nums[i]+nums[i+1])%10); // insert into the temp
            }
            nums = temp; // repeat the process untill our result comes
        }
        return nums[0];
    }
};