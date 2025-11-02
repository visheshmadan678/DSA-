class Solution {
public:
    //code by vishu badmos
    void calc(int x,int y,vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        //move up 
        int i = x;
        int j = y;
        i--;
        while(i>=0){
            if(grid[i][j]==0)grid[i][j]=1;
            if(grid[i][j]==2 || grid[i][j]==3)break;
            i--;
        }

        //move down
        i = x;
        j = y;
         i++;
        while(i<n){
            if(grid[i][j]==0)grid[i][j]=1;
            if(grid[i][j]==2 || grid[i][j]==3)break;
            i++;
        }

        //move left 
        i = x;
        j = y;
        j--;
        while(j>=0){
            if(grid[i][j]==0)grid[i][j]=1;
            if(grid[i][j]==2 || grid[i][j]==3)break;
            j--;
        }


        //move right        
        i = x;
        j = y;
        j++;
        while(j<m){
            if(grid[i][j]==0)grid[i][j]=1;
            if(grid[i][j]==2 || grid[i][j]==3)break;
            j++;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n,0));

        for(auto it:guards){
            grid[it[0]][it[1]] = 2;//allocated guards as 2
        }

        for(auto it:walls){
            grid[it[0]][it[1]] = 3;// 3 is used for walls 
        }

        //rest every cell is zero 

        //now check for every guard mark the cell as 1 visited 
        for(auto it:guards){
            calc(it[0],it[1],grid);
        }

        int ans=0;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && visited[i][j]==0){
                    ans++;
                    visited[i][j] = 1;
                }
            }
        }

        return ans;

    }
};