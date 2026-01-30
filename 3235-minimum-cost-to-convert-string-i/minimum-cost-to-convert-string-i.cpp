class Solution {
public:
    const long long INF = 1e18;

    vector<long long> dijkstra(int src, vector<vector<pair<int,int>>>& adj) {
        vector<long long> dist(26, INF);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto [v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        vector<vector<pair<int,int>>> adj(26);
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u].push_back({v, cost[i]});
        }

        vector<vector<long long>> mindist(26);
        vector<bool> computed(26, false);

        long long ans = 0;

        for (int i = 0; i < source.size(); i++) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if (s == t) continue;

            if (!computed[s]) {
                mindist[s] = dijkstra(s, adj);
                computed[s] = true;
            }

            if (mindist[s][t] == INF)
                return -1;

            ans += mindist[s][t];
        }

        return ans;
    }
};
