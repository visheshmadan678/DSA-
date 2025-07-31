class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxi = 1;
        for(int i=0;i<nums.size();i++){
            int curr = 1;
            int num = nums[i];
            for(int j=i+1;j<nums.size();j++){
                if((nums[j] & num)==0){
                    num |= nums[j];
                    curr++;
                }
                else break;
            }
            maxi = max(curr,maxi);
        }
        return maxi;   
    }
};