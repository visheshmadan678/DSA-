class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[52][52][52];
    int dx[4] = {0, -1, 0, 1}; // declare arrays to traverse and
    int dy[4] = {1, 0, -1, 0}; // y axis
    int recursion(int n, int m, int limit, int x, int y,
                  vector<vector<int>>& visited) {
        if (x < 0 || y < 0 || x >= n || y >= m) {
            return 1;
        }
        if (limit <= 0)
            return 0;

        if(dp[x][y][limit]!=-1)return dp[x][y][limit] % mod;
        
        int count = 0;
        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            count = (count + recursion(n, m, limit - 1, newx, newy, visited)) % mod;
    
        }

        return dp[x][y][limit] =  count%mod; // mark as unvisited
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        memset(dp,-1,sizeof(dp));
        return recursion(m, n, maxMove, startRow, startColumn, visited) % mod;
    }
};