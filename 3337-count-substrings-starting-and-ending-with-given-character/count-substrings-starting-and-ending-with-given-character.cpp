class Solution {
public:
    long long countSubstrings(string s, char c) {
        vector<long long>suffix(s.length());
        int len = s.length();
        long long ans = 0;

        if(s[len-1]!=c)suffix[len-1] = 0;
        else suffix[len-1] = 1; // increase it's counter by one then 

        //to tell upto where i have reached and how many a's are present inside my substring
        for(int i=len-2;i>=0;i--){
            if(s[i]==c){
                suffix[i] = suffix[i+1] + 1;
            }
            else{
                suffix[i] = suffix[i+1];
            }
        }
        
        for(int i=0;i<len-1;i++){
            if(s[i]==c){
                //then add the contribution to our answer
                ans += 1 + suffix[i+1];
            }
        }
        
        if(s[len-1]==c)ans++;
        
        return ans;
    }
};