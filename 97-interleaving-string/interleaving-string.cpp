class Solution {
public:
    int dp[101][101];
    int recursion(int idx1,int idx2,string &s1, string &s2, string &s3){
        if(idx1>=s1.length() && idx2 >=s2.length() && idx1+idx2 >= s3.length())return true;

        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];

        bool result = false;
        if(idx1 < s1.length() && s1[idx1] == s3[idx1+idx2]){
            result = recursion(idx1+1,idx2,s1,s2,s3);
        }

        if(result)return dp[idx1][idx2] = result;


        bool result2 = false;

        if(idx2 < s2.length() && s2[idx2]==s3[idx1+idx2]){
            result2 = recursion(idx1,idx2+1,s1,s2,s3);
        }

        return dp[idx1][idx2] = result2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return recursion(0,0,s1,s2,s3);
    }
};