class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        // code by vishu badmos 
        // badmashi nhi mitar 
        int n = s.length();
        unordered_map<string, int> mp;
        int ans = INT_MIN;
        for (int i = 0; i <= n - minSize; i++) {
            string temp = s.substr(i, minSize); // take the length of the string as min size
            unordered_set<char> st(temp.begin(), temp.end());
            if (st.size() <= maxLetters)
                mp[temp]++;
        }

        for(auto it:mp){
            ans = max(it.second,ans);
        }
        return ans==INT_MIN?0:ans;
    }
};
