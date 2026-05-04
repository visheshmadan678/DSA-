class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        int n = nums.size();
        // rotating a matrix by using extra space
        // today we learnt how to take the transpose of a matrix
        for (int i = 0; i <= n - 2; i++) {
            for (int j = i + 1; j < n; j++) {
                int temp = nums[i][j];
                nums[i][j] = nums[j][i];
                nums[j][i] = temp;
            }
        }
        // cout<<"hello world";
        for (int i = 0; i < n; i++) {
            reverse(nums[i].begin(), nums[i].end());
        }
    }
};