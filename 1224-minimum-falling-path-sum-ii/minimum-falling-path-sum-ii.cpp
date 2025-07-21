class Solution {
public:
    //rule 1. dervie everything in terms of index 
    //rule 2. explore all the paths 
    //rule 3. apply minimum maximum whatever is given in the question
    int recursion(int i,int j,vector<vector<int>>&grid,int n,vector<vector<int>>&dp){
        //so what is the base case if i reaches n then we will return that index
        if(i==n-1)return grid[i][j];
        if(dp[i][j]!=-2)return dp[i][j];
        //lets explore all the paths
        //so we can go anywhere in the next row //except the same column
        //means our j will always be either 0 to j-1 or j+1 to m or nothing else it can be
        int next = INT_MAX;
        // int vnext = INT_MAX;
        for(int k=0;k<n;k++){
            if(k!=j){
                next = min(next,grid[i][j] + recursion(i+1,k,grid,n,dp));
            }
        }
        // i think we have explored all the paths 
        return dp[i][j] = next;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        //lets first right the recursion for this question'
        //now it's time to apply dp on it lets create a dp 
        // of size n * n 
        int n = grid.size();
        vector<vector<int>>dp(n,vector<int>(n,-2)); //dp is just for memoisation
        int ans = INT_MAX;
        int row = 0;
        for(int i=0;i<n;i++){
            ans = min(ans,recursion(row,i,grid,n,dp));
        }
        return ans;
    }
};