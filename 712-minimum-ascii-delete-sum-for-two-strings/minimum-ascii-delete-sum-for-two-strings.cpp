class Solution {
public:
    int dp[1001][1001];
    int recursion(int idx1,int idx2, string &s1, string &s2){
        if(idx1<0){
            int cost=0;
            for(int i=0;i<=idx2;i++){
                cost+= int(s2[i]);
            }
            return cost;
        }
        if(idx2<0){
            int cost1=0;
            for(int i=0;i<=idx1;i++){
                cost1+= int(s1[i]);
            }
            return cost1;
        }

        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];

        if(s1[idx1]==s2[idx2]){
            return dp[idx1][idx2] = recursion(idx1-1,idx2-1,s1,s2);
        }

        return dp[idx1][idx2] = min((int(s1[idx1])+recursion(idx1-1,idx2,s1,s2)),(int(s2[idx2])+recursion(idx1,idx2-1,s1,s2)));
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return recursion(s1.length()-1,s2.length()-1,s1,s2);
    }
};