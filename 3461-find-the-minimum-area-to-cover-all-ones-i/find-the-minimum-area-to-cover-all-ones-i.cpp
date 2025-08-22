class Solution {
public:
    //code by vishu badmos
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size(); // store the coordinates 
        int max_row = INT_MIN;
        int max_col = INT_MIN;
        int min_col = INT_MAX,min_row = INT_MAX;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    max_row = max(max_row,i);
                    max_col = max(max_col,j);
                    min_col = min(min_col,j);
                    min_row = min(min_row,i);
                }
            }
        }
        
        return (max_row-min_row+1) * (max_col-min_col+1);
    }
};