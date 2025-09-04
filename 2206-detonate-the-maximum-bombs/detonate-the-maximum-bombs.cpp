class Solution {
public:
    int n;
    bool inRange(vector<int>& a, vector<int>& b) {
        long long dx = (long long)a[0] - b[0];
        long long dy = (long long)a[1] - b[1];
        long long r = (long long)a[2];
        return dx * dx + dy * dy <= r * r;
    }

    int dfs(int i, vector<int>& visited, vector<vector<int>>& bombs) {
        visited[i] = 1;
        int cnt = 1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && inRange(bombs[i], bombs[j])) {
                cnt += dfs(j, visited, bombs);
            }
        }
        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        n = bombs.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> visited(n, 0);
            ans = max(ans, dfs(i, visited, bombs));
        }
        return ans;
    }
};
