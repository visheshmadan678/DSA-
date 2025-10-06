class Solution {
public:
    //not solved by me i got the intusion but did not thought about the prefix sum 
    int minimizeArrayValue(vector<int>& nums) {
        long long prefixSum = 0;
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int avg = (prefixSum + i) / (i + 1);
            result = max(result, avg);
        }
        return result;
    }
};