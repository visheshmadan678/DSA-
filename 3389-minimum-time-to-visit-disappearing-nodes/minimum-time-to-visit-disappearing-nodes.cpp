class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        // adjacency list: node -> {neighbor, weight}
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> dist(n, 1e9);
        dist[0] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            
            if (time > dist[node]) continue;
            
            if (time >= disappear[node]) continue;
            
            for (auto &[nei, w] : adj[node]) {
                int newTime = time + w;
                if (newTime < dist[nei]) {
                    dist[nei] = newTime;
                    pq.push({newTime, nei});
                }
            }
        }
        
        // Final filtering: mark unreachable or expired nodes as -1
        for (int i = 0; i < n; i++) {
            if ( dist[i] >= disappear[i] || dist[i]==1e9) {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};
