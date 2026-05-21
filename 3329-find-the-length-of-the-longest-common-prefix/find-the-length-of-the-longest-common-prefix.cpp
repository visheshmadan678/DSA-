class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int>mp1,mp2; 

        for(auto &it:arr1){
            string str = to_string(it);
            string temp = "";
            for(int i=0;i<str.length();i++){
                temp += str[i];
                mp1[temp]++;
            }
        }

        for(auto &it:arr2){
            string str = to_string(it);
            string temp = "";
            for(int i=0;i<str.length();i++){
                temp += str[i];
                mp2[temp]++;
            }
        }

        int ans = 0;

        for(auto &it:mp1){
            int len = it.first.length();
            if(mp2.find(it.first) != mp2.end()){
                ans = max(ans,len);
            }
        }

        return ans;
    }
};