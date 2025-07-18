class Solution {
public:
    int recursion(int idx, vector<pair<int,int>>&vec, int m, int n,vector<vector<vector<int>>>&dp){
        if(m<=0 && n<=0)return 0;
        if(idx>=vec.size())return 0;
        if(dp[idx][m][n]!=-1)return dp[idx][m][n];
        int take = 0;
        if(m>=vec[idx].second && n>=vec[idx].first){
                take = 1 + recursion(idx+1,vec,m-vec[idx].second,n-vec[idx].first,dp);
        }
        int not_take = recursion(idx+1,vec,m,n,dp);

        return dp[idx][m][n] = max(take,not_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>vec(strs.size());
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        int size = strs.size();
        for(int i=0;i<size;i++){
            int o = 0;
            int z = 0;
            for(auto it:strs[i]){
                if(it=='0')z++;
                else o++;
            }
            vec[i] = {o,z};
        }
        return recursion(0,vec,m,n,dp);
    }
};