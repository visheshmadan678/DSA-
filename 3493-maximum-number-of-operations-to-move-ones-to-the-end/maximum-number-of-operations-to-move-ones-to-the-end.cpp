class Solution {
public:
    int maxOperations(string str) {
        string s = "";
        for(auto &it:str){
            if(s.empty()){
                s += it;
            }
            else if(s.back() == '0' && it == '0'){
                continue;
            }
            else{
                s += it;
            }
        }

        int n = s.length();
        vector<int>zeroes(s.length());
        if(s[n-1] == '0')zeroes[n-1] = 1;
        else zeroes[n-1] = 0;

        for(int i=n-2;i>=0;i--){
            if(s[i] == '0'){
                zeroes[i] = 1 + zeroes[i+1];
            }
            else{
                zeroes[i] = zeroes[i+1]; // else remain same as it is 
            }
        }


        int ans = 0;

        for(int i=0;i<s.length();i++){
            if(s[i] == '1'){
                ans += zeroes[i];
            }
        }
        
        return ans;
    }
};