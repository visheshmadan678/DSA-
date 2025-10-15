class Solution {
public:
    int maxIncreasingSubarrays(vector<int>&arr) {
        vector<int> nums;
        int i = 0;
        while (i < arr.size()) {
            int count = 1;
            while (i < arr.size() - 1 && arr[i + 1] > arr[i]) {
                count++;
                i++;
            }
            nums.push_back(count); // push that count into the nums
            i++;
        }

        int ans = 1;
        i = nums.size() - 1;

        while (i >= 1) {
            if (nums[i - 1] >= nums[i]) {
                ans = max(ans, nums[i]); // this can also be my answer
            }else {
                ans = max(ans, nums[i-1]);
            }
            if (nums[i] % 2 == 0) {
                ans = max(ans, nums[i] / 2);
            } else {
                ans = max(ans, (nums[i] - 1) / 2);
            }
            i--;
        }

        if (nums[0] % 2 == 0) {
            ans = max(ans, nums[0] / 2);
        } else {
            ans = max(ans, (nums[0] - 1) / 2);
        }

        return ans;
    }
};