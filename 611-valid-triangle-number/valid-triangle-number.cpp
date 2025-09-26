class Solution {
public:
    int giveindex(int left, int right, vector<int>& nums, int i, int j) {

        // int left = j+1;
        // int right = n-1;
        int ans = -1;
        while (left<=right) {
            int mid = (left+right)/2;
            if (nums[mid] >= nums[i] + nums[j]) {
                // it means we have to reduce the search space
                right = mid - 1;
            } else {
                ans = mid;
                left = mid + 1;
                // go for the more larger index
            }
        }

       return ans;

    }
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        sort(nums.begin(), nums.end());
        // took the hint from the chat gpt
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                // for every pair i and j find the largest valid index
                int index = giveindex(j + 1, n - 1, nums, i, j);
                if (index != -1)
                    count += (index-(j+1)+1);
            }
        }

        return (int)count;
    }
};