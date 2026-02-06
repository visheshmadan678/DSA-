class Solution {
public:
    //code by vishu badmos
    //badmashi nahi mitar
    int binary_search(int left, int right, vector<int>& nums, long long target) {
        int idx = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= target) {
                idx = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return idx;
    }
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); int len = nums.size();
        int ans = INT_MAX;

        for (long long i = 0; i < len; i++) {
            long long target = 1LL * nums[i] * k;
            int idx = binary_search(i + 1, len - 1, nums, target);
            if (idx != -1) {
                int inter_ele = idx - i + 1;
                ans = min(ans, len - inter_ele);
            } else {
                ans = min(ans, len - 1);
            }
        }
        return ans;
    }
};