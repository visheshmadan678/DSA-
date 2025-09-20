class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph; 
        unordered_map<string, int> indegree; 

        for (int i = 0; i < recipes.size(); i++) {
            string recipe = recipes[i];
            indegree[recipe] = ingredients[i].size();
            for (auto &ing : ingredients[i]) {
                graph[ing].push_back(recipe);
            }
        }


        queue<string> q;
        unordered_set<string> supplySet(supplies.begin(), supplies.end());

        for (auto &s : supplies) q.push(s);

        vector<string> answer;

        while (!q.empty()) {
            string node = q.front();
            q.pop();
            if (indegree.count(node) && indegree[node] == 0) {
                answer.push_back(node);
                supplySet.insert(node);
            }
            for (auto &next : graph[node]) {
                indegree[next]--;
                if (indegree[next] == 0) q.push(next); 
            }
        }

        return answer;
    }
};
