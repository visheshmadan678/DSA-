class Solution {
public:
    
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        q.push(s);
        string ans = s;
        unordered_set<string> visited;
        visited.insert(s);

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            ans = min(ans, curr);
            string added = curr;
            for (int i = 1; i < added.size(); i += 2) {
                added[i] = ((added[i] - '0' + a) % 10) + '0';
            }

            if (!visited.count(added)) {
                visited.insert(added);
                q.push(added);
            }

            string rotated = curr.substr(curr.size() - b) + curr.substr(0, curr.size() - b);
            if (!visited.count(rotated)) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }

        return ans;
    }
};
