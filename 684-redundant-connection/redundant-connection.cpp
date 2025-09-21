class Solution {
public:
    set<vector<int>>ans;
    void dfs(int node, int parent,unordered_map<int,vector<int>>&mp,vector<int>&visited){
        visited[node] = 1;
        for(auto &it:mp[node]){
            if(!visited[it])dfs(it,node,mp,visited);
            else if(visited[it] && it!=parent){
                ans.insert({it,node});
            }
        }
        visited[node] = 0;
        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mp;
        for(auto it:edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]); // make a bidirection graph
        }
        vector<int>visited(edges.size()+1,0); // take a visited vector
        for(int i=1;i<=edges.size();i++)dfs(i,-1,mp,visited);
        
        for(int i=edges.size()-1;i>=0;i--){
            if(ans.count(edges[i]))return edges[i];
        }
        return {};
    }
};