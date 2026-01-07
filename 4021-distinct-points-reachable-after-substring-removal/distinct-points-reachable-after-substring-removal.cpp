class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        unordered_set<string> st;
        unordered_map<char, int> mp;

        // Count moves outside the first removed substring [0..k-1]
        for (int i = k; i < n; i++) {
            mp[s[i]]++;
        }

        int x = mp['R'] - mp['L'];
        int y = mp['U'] - mp['D'];
        st.insert(to_string(x) + "," + to_string(y));

        // Slide the removed window
        for (int i = k; i < n; i++) {
            // character enters removed window → remove from remaining moves
            mp[s[i]]--;

            // character leaves removed window → add back
            mp[s[i - k]]++;

            x = mp['R'] - mp['L'];
            y = mp['U'] - mp['D'];
            st.insert(to_string(x) + "," + to_string(y));
        }

        return st.size();
    }
};
