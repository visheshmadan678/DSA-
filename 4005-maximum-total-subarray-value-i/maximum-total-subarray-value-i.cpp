class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long low  = *min_element(nums.begin(),nums.end());
        long long high = *max_element(nums.begin(),nums.end());
        return k * (high - low);
    }
};