class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        int m = grid.size();  int n = grid[0].size();

        vector<vector<long long>>grid1(m, vector<long long>(n,0));
        vector<vector<long long>>grid2(m, vector<long long>(n,0));

        for(int i=0;i<m;i++){
            total += grid[i][0];
            grid1[i][0] = grid[i][0];
        }

        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                total += grid[i][j];
                grid1[i][j] = grid1[i][j-1] + grid[i][j];
            }
        }

        for(int i=0;i<n;i++){
            grid2[0][i] = grid[0][i];
        }

        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                grid2[j][i] = grid[j][i] + grid2[j-1][i];
            }
        }

        long long sum = 0;
        for(int i = 0; i < m;  i++){
            sum += grid1[i][n-1];
            if(sum == (total - sum)){
                return true;
            }
        }

        sum = 0;
        for(int i = 0; i < n; i++){
            sum += grid2[m-1][i];
            if(sum  == total - sum){
                return true;
            }
        }

        return false;

    }
};