class Solution {
public:
    int m1, n1;
    int dp[500][500][3];
    //madarchod question
    int recursion(int i, int j, vector<vector<int>>& coins, int neutral) {
        if (i >= m1 || j >= n1)
            return INT_MIN/2;

        if (i == m1 - 1 && j == n1 - 1) {
            if (coins[i][j] < 0 && neutral > 0)
                return 0;
            return coins[i][j];
        }


        if(dp[i][j][neutral] != INT_MIN)return dp[i][j][neutral];
        
        int a = INT_MIN/2;
        int b = INT_MIN/2;
        int c = INT_MIN/2;
        int d = INT_MIN/2;

        a = coins[i][j] +
            recursion(i + 1, j, coins, neutral); // go down after picking
        b = coins[i][j] +
            recursion(i, j + 1, coins, neutral); // go right after picking

        //on every cell i cannot neutralize i can only neturalize the robbers 
        if (coins[i][j] < 0 && neutral > 0) {
            c = recursion(i + 1, j, coins,
                          neutral - 1); // either go down after neutral
            d = recursion(i, j + 1, coins,
                          neutral - 1); // either go right after neutral
        }

        return dp[i][j][neutral] = max({a, b, c, d});
    }
    int maximumAmount(vector<vector<int>>& coins) {
        for(int i=0;i<500;i++)
    for(int j=0;j<500;j++)
        for(int k=0;k<3;k++)
            dp[i][j][k] = INT_MIN;
        int m = coins.size();
        int n = coins[0].size();
        m1 = m;
        n1 = n;
        return recursion(0, 0, coins, 2);
    }
};