class Solution {
public:
    void change(int x, int y, vector<vector<int>>& grid, int len) {
        int yrange = y + len; // column end (exclusive)

        // Swap rows inside submatrix
        for (int i = 0; i < len / 2; i++) {
            for (int j = y; j < yrange; j++) {
                swap(grid[x + i][j], grid[x + len - 1 - i][j]);
            }
        }
    }

    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        change(x, y, grid, k);
        return grid;
    }
};