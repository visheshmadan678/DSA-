class Solution {
public:
    bool dijkstra(int mid, int src, int target, long long limit, vector<vector<pair<int, long long>>>& adjlist) {
        vector<long long> distance(adjlist.size(), LLONG_MAX);
        distance[src] = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> qt;
        qt.push({0, src});

        while (!qt.empty()) {
            int node = qt.top().second;
            long long dist = qt.top().first;
            qt.pop();

            if (dist > distance[node]) continue;
            if (node == target) return true;

            for (auto& [neighbour, cost] : adjlist[node]) {
                if (cost < mid) continue;
                if (dist + cost > limit) continue;

                if (dist + cost < distance[neighbour]) {
                    distance[neighbour] = dist + cost;
                    qt.push({distance[neighbour], neighbour});
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, long long>>> adjlist(n); 
        long long maxweight = -1;

        for (auto& it : edges) {
            int u = it[0], v = it[1];
            long long w = it[2]; 

            if (online[u] && online[v]) {
                adjlist[u].push_back({v, w});
                maxweight = max(maxweight, w);
            }
        }

        long long l = 0, h = maxweight, ans = -1;
        while (l <= h) {
            long long mid = l + (h - l) / 2;
            if (dijkstra(mid, 0, n - 1, k, adjlist)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return ans;
    }
};
