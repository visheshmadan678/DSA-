class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); 
        for(int i=0;i<n;i++){
            int j = 0;
            int k = i;
            vector<int>ds;
            while(k<n && j<m){
                ds.push_back(grid[k][j]);
                k++;
                j++;
            }
            sort(ds.rbegin(), ds.rend());
            j = 0;
            k = i;
            int iter = 0;
            while(k<n && j<m){
                grid[k][j] = ds[iter++];
                k++;
                j++;
            }
        }

        for(int j=1;j<m;j++){
            int i = 0;
            int k = j;
            vector<int>ds;
            while(i<n && k<m){
                ds.push_back(grid[i][k]); 
                i++;
                k++;
            }
            sort(ds.begin(), ds.end());
            i = 0;
            k = j;
            int iter = 0;
            while(i<n && k<m){
                grid[i][k] = ds[iter++];
                i++;
                k++;
            }
        }

        return grid;
    }
};
