class Solution {
public:
    unordered_map<string, bool> memo;
    bool dfs(int idx, string &curr, string &next,
             unordered_map<string, vector<char>> &mp) {
        if (idx == 0 && memo.count(curr))
            return memo[curr];

        if (curr.size() == 1)
            return memo[curr] = true;

        if (next.size() == curr.size() - 1) {
            string newCurr = next;
            string newNext = "";
            bool res = dfs(0, newCurr, newNext, mp);
            memo[curr] = res;
            return res;
        }

        string key = curr.substr(idx, 2);
        if (!mp.count(key))
            return false;

        for (char ch : mp[key]) {
            next.push_back(ch);
            if (dfs(idx + 1, curr, next, mp))
                return true;
            next.pop_back();
        }

        if (idx == 0)
            memo[curr] = false;

        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        for (auto &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        string next = "";
        return dfs(0, bottom, next, mp);
    }
};
