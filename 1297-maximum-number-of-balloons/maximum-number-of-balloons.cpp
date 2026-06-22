class Solution {
public:
    #define rep(i, n) for (int i = 0; i < (n); i++)
    int maxNumberOfBalloons(string text) {
        map<char,long long>mp;

        rep(i,text.length()){
            mp[text[i]]++; // store the value inside the map
        }

        long long ans = INT_MAX;

        if(mp['b'] && mp['a'] && mp['l'] >= 2 && mp['o'] >= 2 && mp['n']){
            ans = min({mp['b'], mp['a'], mp['l'] / 2, mp['o'] / 2, mp['n']});
        }
        else{
            return 0;
        }
        
        return ans; // return ans in the end 
    }   
};