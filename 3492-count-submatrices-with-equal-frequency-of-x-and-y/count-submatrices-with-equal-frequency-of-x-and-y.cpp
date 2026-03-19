class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>>x_count(m,vector<int>(n,0)); //for storing the count of x
        vector<vector<int>>y_count(m,vector<int>(n,0)); // for storing the count of y 

        for(int i=0;i<n;i++){
            if(grid[0][i] == 'X'){
                x_count[0][i] = 1;
            }
            else{
                x_count[0][i] = 0; 
            }
        }

        //i is for column and j is for rows 
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                if(grid[j][i] == 'X'){
                    x_count[j][i] = 1 + x_count[j-1][i];
                }
                else{
                    x_count[j][i] = x_count[j-1][i];
                }
            }
        }

    
        for(int i=0;i<n;i++){
            if(grid[0][i] == 'Y'){
                y_count[0][i] = 1;
            }
            else{
                y_count[0][i] = 0; 
            }
        }

        //i is for column and j is for rows 
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                if(grid[j][i] == 'Y'){
                    y_count[j][i] = 1 + y_count[j-1][i];
                }
                else{
                    y_count[j][i] = y_count[j-1][i];
                }
            }
        }

        //now iterate through the all submatrices and check for the answer 
        int ans = 0; // for storing the answer 
        for(int i=0;i<m;i++){
            int x = 0, y = 0;
            for(int j=0;j<n;j++){
                x += x_count[i][j];
                y += y_count[i][j];
                if(x !=0 && x == y){
                    ans++;
                }
            }
        }

        return ans;
    }
};