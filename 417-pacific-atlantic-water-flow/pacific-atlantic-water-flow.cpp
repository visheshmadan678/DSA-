class Solution {
public:
    int sizex,sizey;
    bool atlantic; bool pacific;
    vector<vector<int>>ds = {{1,0},{0,1},{-1,0},{0,-1}}; 
    void dfs(int x, int y,vector<vector<int>>&visited,vector<vector<int>>&heights){
        if(pacific && atlantic)return;
        visited[x][y] = 1;
        for(auto &it:ds){
            int newx = it[0] + x;
            int newy = it[1] + y;
            if(newx >=0 && newy>=0 && newx < sizex && newy < sizey && !visited[newx][newy] && heights[newx][newy] <= heights[x][y]){
                dfs(newx,newy,visited,heights);
            }
            else if(newx <0 || newy<0){
                pacific = true;
            }
            else if(newx >= sizex || newy >= sizey){
                atlantic = true;
            }
        }
        visited[x][y] = 0;
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(); int m = heights[0].size();
        vector<vector<int>>results;
        sizex = n;
        sizey = m;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                atlantic = false;
                pacific = false;
                dfs(i,j,visited,heights);
                if(atlantic && pacific){
                    results.push_back({i,j});
                }
            }
        }
        return results;
    }
};