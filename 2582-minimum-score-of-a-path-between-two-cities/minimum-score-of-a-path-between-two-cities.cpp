class Solution {
public:
    int ans = INT_MAX;
    int last;
    vector<int> visited;

    void dfs(int node, vector<vector<pair<int,int>>>& adjlist, int dist) {
        visited[node] = 1;

        for (auto it : adjlist[node]) {
            int new_dist = it.second;
            ans = min(ans, new_dist);
            if (!visited[it.first]) {
                dfs(it.first, adjlist, new_dist);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        last = n;
        vector<vector<pair<int,int>>> adjlist(n+1);
        visited.assign(n+1, 0);

        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            adjlist[u].push_back({v, cost});
            adjlist[v].push_back({u, cost});
        }


        dfs(1,adjlist,INT_MAX);
     
        return ans;
    }
};
