class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            int trailingOnes = 0;
            int temp = x;
            while (temp & 1) {      
                trailingOnes++;
                temp >>= 1;          
            }

            if (trailingOnes == 0) {
                ans[i] = -1;
                continue;
            }

            int candidate = x - (1 << (trailingOnes - 1));

            if ((candidate | (candidate + 1)) == x) {
                ans[i] = candidate;
            } else {
                ans[i] = -1;
            }
        }

        return ans;
    }
};