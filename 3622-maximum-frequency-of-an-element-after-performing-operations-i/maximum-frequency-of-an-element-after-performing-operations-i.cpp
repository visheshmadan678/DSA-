
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;

        for (int target = 1; target <= 100000; ++target) {
            // Count numbers within [target - k, target + k]
            int left = lower_bound(nums.begin(), nums.end(), target - k) - nums.begin();
            int right = upper_bound(nums.begin(), nums.end(), target + k) - nums.begin();
            int reachable = right - left;

            // Count how many are already equal to target
            int eqL = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            int eqR = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            int equals = eqR - eqL;

            int freq = min(reachable, equals + numOperations);
            ans = max(ans, freq);
        }

        return ans;
    }
};
