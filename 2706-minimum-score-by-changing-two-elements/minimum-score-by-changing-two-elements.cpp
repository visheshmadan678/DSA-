class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //so i can change two elements and i want to minimize the score 
        int n = nums.size();
        if(n == 3){
            //i the size of the array is 3 then always the answer  will be zero 
            return 0; // straight away return zero as the answer;
        }
        return min({abs(nums[0]-nums[nums.size()-3]),abs(nums[nums.size()-1]-nums[2]),abs(nums[1]-nums[nums.size()-2])});
    }   
};