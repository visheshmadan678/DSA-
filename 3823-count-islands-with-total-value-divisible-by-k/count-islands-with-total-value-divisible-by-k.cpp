class Solution {
public:
    vector<long long>sums; // global vector to store the sums;

    long long recursion(int x, int y, vector<vector<int>>&grid, vector<vector<int>>&visited){

        int n = grid.size();
        int m = grid[0].size();
        
        visited[x][y] = 1; // marking the index as visited 
        long long  sum = 0;
        sum = grid[x][y]; // the initial sum on a valid index 

        int dx[4] = {0,-1,1,0};
        int dy[4] = {1,0,0,-1}; 

        for(int k=0; k<4; k++){
            int nx = x + dx[k]; // the new indices
            int ny = y + dy[k]; // the new indices 

            //add the valid conditions 
            if(nx>=0 && ny>=0 && nx<n  && ny<m && !visited[nx][ny] && grid[nx][ny]!=0){
                sum += recursion(nx,ny,grid,visited); // call the next recursion function
            }
        }
        return sum;
    }

    
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0)); //initially marking all of them as unvisited 
        //itertiing through our grid vector to store the count;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]!=0){
                    //if it's a valid cell 
                    int sum = recursion(i,j,grid,visited);
                    sums.push_back(sum);
                }
            }
        }
        int cnt = 0;
        for(auto it:sums){
            if(it%k==0)cnt++;
        }

        return cnt;
    }
};