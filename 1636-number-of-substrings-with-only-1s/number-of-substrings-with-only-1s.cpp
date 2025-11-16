class Solution {
public:
    int numSub(string s) {
        int i = 0; 
        int size = s.length();
        int ans = 0; int mod = 1e9 + 7;
        while(i < size){
            int count = 0;
            while(i < s.length() && s[i]=='1'){
                count++;
                i++;
            }
            ans += (((1LL * count * (count +1)) % mod)/2) % mod;           
            i++;   
        }
        return ans % mod;
    }
};