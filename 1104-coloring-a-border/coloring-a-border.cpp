class Solution {
public:
    int r; int c;
    int d[4][2] = {{-1,0},{1,0},{0,1},{0,-1}}; // today we will use this kind of coordinate system
    int sizer; int sizec;
    void dfs(int x, int y, vector<vector<int>>&grid, vector<vector<int>>&visited){
        visited[x][y] = 1; // mark it as visited 
        //main jaunga hi nhi agar mujko usse alag element mila toh
        for(auto it:d){
            int newx = x + it[0]; int newy = y + it[1]; // assign the new coordinates for traversal
            if(newx<sizer && newx>=0 && newy<sizec && newy>=0 && !visited[newx][newy] && grid[newx][newy]==grid[r][c]){
                //if it's not visited and it is same as the starting cell i mean both the cells share the same value with each other
                dfs(newx,newy,grid,visited);
            }
        }
        return;
    }

    bool check(int x, int y,vector<vector<int>>&visited){
        //i have to color only the cells which are connecting to the border of the the connected componenet
        int d[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        bool flag = false;
        for(auto it:d){
            int newx = x + it[0];
            int newy = y + it[1];
            //uske chaaro taraf visited cells hone chahiye sirf
            if(newx<sizer && newx>=0 && newy<sizec && newy>=0){
                if(visited[newx][newy]==1){
                    flag = false;
                }
                else{
                    flag = true;
                    break;
                }
            } 
            else{
                flag = true;
                break;
            }
        }
        return flag;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        //so i will go by first approach first and that is first find the connected component
        int n = grid.size();
        int m  = grid[0].size();
        sizer = n;
        sizec = m;
        r = row;
        c = col;
        
        vector<vector<int>>visited(n,vector<int>(m,0)); // i will mark only visited those who are the part 
        //of the connected component
        dfs(row,col,grid,visited);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] && check(i,j,visited)){
                    grid[i][j] = color;
                }
            }

        }

        return grid;
    }
};