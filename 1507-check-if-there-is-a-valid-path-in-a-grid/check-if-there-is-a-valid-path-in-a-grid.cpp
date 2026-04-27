class Solution {
public:
    //code by vishu badmos
    //badmosi nahi mitar
    int n,m;
    vector<vector<int>>d = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>>dir = {{0,0,0,0},{1,1,0,0},{0,0,1,1},{1,0,0,1},{0,1,0,1},{1,0,1,0},{0,1,1,0}};
    bool check(int x, int y, int nx, int ny,vector<vector<int>>&grid){
       int num = grid[x][y];
       vector<int>source = dir[num];

       int num2 = grid[nx][ny];
       vector<int>destination = dir[num2];

       //now check if we can reach the destination using the source or not 
       if(source[2] == 1 &&  destination[3] == 1 && y == ny){
            //it means they can connect only if source is above the destination
            if(nx == x - 1){
                return true;
            }
       }

       if(source[3] == 1 && destination[2] == 1 && y == ny){
            if(nx == x + 1){
                return true;
            }
       }


       if(source[1] == 1 && destination[0] ==  1 && x == nx){
            if(ny == y + 1){
                return true;
            }
       }
       
       if(source[0] == 1 && destination[1] == 1 && x == nx){
            if(ny == y - 1){
                return true;
            }
       }

        return false;
    }

    bool solve(int x, int y,vector<vector<int>>&grid,vector<vector<int>>&visited){
        
        if(x == n-1 && y == m-1){
            return true; // straight away return the true as the answer
        }
        visited[x][y] = 1; // mark the cell as the visited cell 

        for(auto &it:d){
            int nx = x + it[0]; int ny = y + it[1];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == 0){
                //now before travelling to the next cell i have to make sure that if they are connected or not or else how will i tavel to the next cell ? 
                if(check(x,y,nx,ny,grid)){
                    bool flag = solve(nx,ny,grid,visited);
                    if(flag)return true; // return true; as it is 
                }
            }
        }


        visited[x][y] = 0; // back track and mark the cell as unvisited 
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int up = -1, down = -1, left = -1, right = -1;
        n = grid.size(); m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));

        return solve(0,0,grid,visited);
    }
};