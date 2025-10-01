class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> qt;
        int len = s.length();
        vector<int> visited(s.length(),0);
        visited[0] = 1;
        int seen = 0;
        qt.push(0); // push the starting index
        while (!qt.empty()) {
            int idx = qt.front();
            qt.pop();
            if (idx == s.length() - 1) return true;
            for (int i = max(seen,idx+minJump); i <= min(idx + maxJump, len-1);i++) {
                if (s[i] == '0') {
                    qt.push(i);
                }
            }
            seen = min(idx + maxJump + 1, len);
        }
        return false;   
    }
};