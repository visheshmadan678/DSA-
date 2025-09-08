class Solution {
public:
    vector<double> ans;

    double roundTo5(double x) {
        return round(x * 1e5) / 1e5; 
    }

    double dfs(string src, string dest, unordered_map<string, vector<pair<string,double>>>& adjlist, unordered_set<string>& visited) {
        if (src == dest) return 1.0;
        visited.insert(src);

        for (auto& it : adjlist[src]) {
            if (!visited.count(it.first)) {
                double res = dfs(it.first, dest, adjlist, visited);
                if (res != -1.0) {
                    return it.second * res; 
                }
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> adjlist;

        for (int i = 0; i < equations.size(); i++) {
            string src = equations[i][0];
            string dest = equations[i][1];
            double cost = values[i];
            adjlist[src].push_back({dest, cost});
            adjlist[dest].push_back({src, 1.0 / cost});
        }


        for (auto it : queries) {
            string src = it[0];
            string dest = it[1];
            if (adjlist.find(src) == adjlist.end() || adjlist.find(dest) == adjlist.end()) {
                ans.push_back(-1.00000);
                continue;
            }
            unordered_set<string> visited;
            double val = dfs(src, dest, adjlist, visited);
            if (val == -1.0) ans.push_back(-1.00000);
            else ans.push_back(roundTo5(val)); 
        }

        return ans;
    }
};
