class Solution {
public:
    string getSmallestString(string s, int k) {
        int len = s.length();
        string ans = s;
        for(int i=0;i<s.length() && k>0;i++){
            int id = ans[i]-'a';
            int cost = min(id,26-id);
            if(cost<=k){
                ans[i] = 'a';
                k -= cost;
            }
            else{
                ans[i] = char(ans[i]-k);
                k = 0;
            }
        }
        return ans;
    }
};