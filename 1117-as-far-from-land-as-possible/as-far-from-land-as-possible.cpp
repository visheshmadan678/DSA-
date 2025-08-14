class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        //the question arises how to implement it 
        int distance = 0;
        int n = grid.size(), m = grid[0].size();  // initialsize the sizes
        vector<vector<int>>visited(n,vector<int>(m,0)); 
        queue<pair<int,int>>qt;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    visited[i][j] = 1;
                    qt.push({i,j}); // push all the islands into the queue 
                }
            }
        }

         // initially mark everything as unvisitted 

        while(!qt.empty()){
            int size = qt.size();
            for(int i=0;i<size;i++){
                pair<int,int>q = qt.front();
                qt.pop();    
                int x = q.first;
                int y = q.second;

                int dx[4] = {1,0,-1,0};
                int dy[4] = {0,1,0,-1};

                for(int k=0;k<4;k++){
                    int newx = x + dx[k]; // new indices 
                    int newy = y + dy[k]; // new indices 

                    if(newx>=0 && newy>=0 && newx<n && newy<m && !visited[newx][newy] && grid[newx][newy]==0){
                        visited[newx][newy]=1;
                        qt.push({newx,newy});
                    }
                }
            }
            distance++;
        }

        if(distance==1)return -1;

        return distance-1;
    }
};