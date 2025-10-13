class Solution {
public:
    //code by vishu badmos
    bool check(string &a, string &b){
        unordered_map<char,int>mp1,mp2;
        for(auto &it:a)mp1[it]++;
        for(auto &it:b)mp2[it]++;
        return mp1 == mp2; // if both the maps are equal or not 
    }
    vector<string> removeAnagrams(vector<string>& words) {
        //why can't i do this with a stack ?  
        stack<string>st;
        int n = words.size();
        st.push(words[0]); // push the first element into the string
        for(int i=1;i<n;i++){
            if(check(words[i],words[i-1])){
                continue;
            }
            else{
                st.push(words[i]);
            }
        }

        vector<string>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};