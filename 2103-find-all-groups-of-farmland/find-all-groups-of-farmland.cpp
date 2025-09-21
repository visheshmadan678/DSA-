class Solution {
public:
    pair<int,int>p = {-1,-1}; // a global pair representing the maximum x and y for our current
    int d[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    int sizex, sizey;
    void dfs(int x, int y, vector<vector<int>>&visited,vector<vector<int>>&land){
        if((p.first+p.second)<(x+y))p = {x,y}; // change the value of p to check for the highest value
        //mark as visitied
        visited[x][y] = 1; // mark the current cell as visitied
        for(auto &it:d){
            int newx = x + it[0];
            int newy = y + it[1];
            if(newx>=0 && newx<sizex && newy>=0 && newy<sizey && !visited[newx][newy] && land[newx][newy]==1){
                dfs(newx,newy,visited,land);
            }
        }
        return;
    } 
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
       int n = land.size();
       int m = land[0].size();
       sizex = n;
       sizey = m;
       vector<vector<int>>visited(n,vector<int>(m,0)); // take a visited array 
       vector<vector<int>>ans;
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1 && !visited[i][j]){
                    dfs(i,j,visited,land); // this will change the value of p 
                    pair<int,int>q = p; // make q is equal to the global pair which is the current maximum
                    p = {-1,-1}; // change value again of p to -1 and -1
                    ans.push_back({i,j,q.first,q.second});
                }
            }
       }

       return ans; // return the answer at the end of the day
    }
};