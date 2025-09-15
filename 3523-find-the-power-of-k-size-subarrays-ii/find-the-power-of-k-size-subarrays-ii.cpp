class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1, -1);

        int start = 0;
        for (int i = 1; i <= n; i++) {
            if (i == n || nums[i] != nums[i - 1] + 1) {
                int end = i - 1; 
                int len = end - start + 1;
                if (len >= k) {
                    for (int j = start; j + k - 1 <= end; j++) {
                        res[j] = nums[j + k - 1];
                    }
                }
                
                start = i;
            }
        }

        return res;
    }
};
