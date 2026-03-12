class Solution {
public:
    //code by vishu badmos 
    //badmashi nahi mitar
    int mod = 1e9 + 7;
    int dp[202][202][2];
    int recursion(int ones, int zeroes, bool flag, int limit){
        if(ones == 0 && zeroes == 0)return 1; // it means the array is made 

        if(dp[ones][zeroes][flag]!=-1)return dp[ones][zeroes][flag];
        int ans = 0;

        if(flag == 1){
            for(int i=1;i <= min(ones,limit); i++){
                ans = (ans + recursion(ones-i,zeroes,false,limit) % mod) % mod;
            }
        }
        else{
            for(int i=1;i <= min(zeroes,limit); i++){
                ans = (ans + recursion(ones,zeroes-i,true,limit) % mod) % mod;
            }
        }

        return dp[ones][zeroes][flag] = ans % mod;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        //was on the right track to solve this problem 
        int a = recursion(zero,one,true,limit) % mod;
        int b = recursion(zero,one,false,limit) % mod;
        
        return (a+b) % mod;
    }
};