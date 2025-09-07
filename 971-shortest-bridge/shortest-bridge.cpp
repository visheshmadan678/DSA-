class Solution {
public:
    int n;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int x, int y, vector<vector<int>>& grid, 
             vector<vector<int>>& visited, queue<pair<int,int>>& q) {
        if(x < 0 || y < 0 || x >= n || y >= n) return;
        if(visited[x][y] || grid[x][y] == 0) return;

        visited[x][y] = 1;
        q.push({x,y});
        for(auto& d : dirs){
            dfs(x+d[0], y+d[1], grid, visited, q);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int,int>> q;

        // Step 1: find one island and push into queue
        bool found = false;
        for(int i=0;i<n && !found;i++){
            for(int j=0;j<n && !found;j++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid, visited, q);
                    found = true;
                }
            }
        }

        
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x,y] = q.front(); q.pop();
                for(auto& d : dirs){
                    int nx = x + d[0], ny = y + d[1];
                    if(nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]){
                        if(grid[nx][ny] == 1){
                            return level;
                        }
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
