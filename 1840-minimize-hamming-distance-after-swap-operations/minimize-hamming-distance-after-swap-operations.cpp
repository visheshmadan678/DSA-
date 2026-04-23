class Solution {
public:
    void dfs(int node, int parent_node,
             unordered_map<int, unordered_map<int,int>>& mp,
             unordered_map<int, vector<int>>& graph,
             vector<int>& visited,
             vector<int>& parent,
             vector<int>& source) {

        visited[node] = 1;
        parent[node] = parent_node;
        mp[parent_node][source[node]]++;

        for (auto &it : graph[node]) {
            if (!visited[it]) {
                dfs(it, parent_node, mp, graph, visited, parent, source);
            }
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {

        int n = source.size();

        unordered_map<int, unordered_map<int,int>> mp;
        unordered_map<int, vector<int>> graph;

        for (auto &it : allowedSwaps) {
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> visited(n, 0);
        vector<int> parent(n, -1);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, i, mp, graph, visited, parent, source);
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int p = parent[i];

            if (mp[p][target[i]] > 0) {
                mp[p][target[i]]--;
            } else {
                ans++; 
            }
        }

        return ans;
    }
};