class Solution {
public:
    int countBinarySubstrings(string s) {
        int size = s.length();
        vector<int>aage_se_zero(s.length()); vector<int>piche_se_zero(s.length());
        vector<int>piche_se_one(s.length()); vector<int>aage_se_one(s.length());

        if(s[0] == '0'){
            aage_se_zero[0] = 1;
        }

        for(int i=1;i<size;i++){
            if(s[i] == '0'){
                aage_se_zero[i] = 1 + aage_se_zero[i-1];
            }
            else{
                aage_se_zero[i] = 0;
            }
        }

        if(s[0] == '1'){
            aage_se_one[0] = 1;
        }

        for(int i=1;i<size;i++){
            if(s[i] == '1'){
                aage_se_one[i] = 1 + aage_se_one[i-1];
            }
            else{
                aage_se_one[i] = 0;
            }
        }

        if(s[size-1] == '0'){
            piche_se_zero[size-1] = 1;
        }

        for(int i=size-2;i>=0;i--){
            if(s[i] == '0'){
                piche_se_zero[i] = 1 + piche_se_zero[i+1];
            }
            else{
                piche_se_zero[i] = 0;
            }
        }

        if(s[size-1] == '1'){
            piche_se_one[size-1] = 1;
        }

        for(int i=size-2;i>=0;i--){
            if(s[i] == '1'){
                piche_se_one[i] = 1 + piche_se_one[i+1];
            }
            else{
                piche_se_one[i] = 0;
            }
        }

        int ans = 0;

        for(int i=0;i<size-1;i++){
            if(aage_se_zero[i]!= 0 &&  piche_se_one[i+1]!=0){
                ans += min(aage_se_zero[i],piche_se_one[i+1]);
            }

            if(aage_se_one[i] != 0 &&  piche_se_zero[i+1]!=0){
                ans += min(aage_se_one[i],piche_se_zero[i+1]);
            }
        }

        return ans;
    }
};