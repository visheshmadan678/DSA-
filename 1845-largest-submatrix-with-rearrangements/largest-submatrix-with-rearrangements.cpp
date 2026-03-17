class Solution {
public:
    //code by vishu badmos 
    // badmashi nahi mitar
    int largestSubmatrix(vector<vector<int>>&nums) {
        int ans = 0;
        int m = nums.size();
        int n = nums[0].size();

        // take the prefix sum column wise for every column
        vector<vector<int>> prefix(nums.size(), vector<int>(nums[0].size(), 0));

        for (int i = 0; i < n; i++) {
            if (nums[m - 1][i] == 1) {
                prefix[m - 1][i] = 1;
            } else {
                prefix[m - 1][i] = 0;
            }
        }

        // i is for column and j is for rows
        for (int i = 0; i < n; i++) {
            for (int j = m - 2; j >= 0; j--) {
                if (nums[j][i] == 1) {
                    prefix[j][i] = 1 + prefix[j + 1][i];
                } else {
                    prefix[j][i] = 0;
                }
            }
        }

        for (auto& it : prefix) {
            sort(it.rbegin(), it.rend());
        }

        for (int i = 0; i < m; i++) {
            int length = 1;
            for (int j = 0; j < n; j++) {
                int ele = prefix[i][j];
                ans = max(ans, ele * length);
                length++;
            }
        }

        return ans;
    }
};