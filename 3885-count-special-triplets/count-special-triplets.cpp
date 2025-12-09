class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int MOD = 1e9 + 7;
        unordered_map<int, long long> left, right;
        for (int x : nums) {
            right[x]++;
        }

        long long count = 0;
        for (int j = 0; j < nums.size(); j++) {
            int mid = nums[j];
            right[mid]--; 
            int target = 2 * mid;
            if (left.count(target) && right.count(target)) {
                count = (count + left[target] * right[target]) % MOD;
            }
            left[mid]++;
        }

        return count;
    }
};
