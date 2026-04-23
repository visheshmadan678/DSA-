class Solution {
public:
    void dfs(int node,int parent_node,unordered_map<int,unordered_map<int,int>>&mp,unordered_map<int,vector<int>>&graph,vector<int>&visited,vector<int>&parent,vector<int>&source){

        visited[node] = 1; // mark the node as visited 
        mp[parent_node][source[node]]++;
        parent[node] = parent_node;

        for(auto &it: graph[node]){
            if(!visited[it]){
                dfs(it,parent_node,mp,graph,visited,parent,source);
            }
        }

        return;
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        unordered_map<int,unordered_map<int,int>>mp;
        vector<int>parent(source.size(),-1); // initially subka baap minus one hai lets suppose

        unordered_map<int,vector<int>>graph;

        for(auto &it:allowedSwaps){
            int source = it[0]; int destination = it[1];
            graph[source].push_back(destination);
            graph[destination].push_back(source); // make a bidirectional graph 
        }

        vector<int>visited(source.size(),0);

        for(int i=0;i<source.size();i++){
            if(!visited[i]){
                dfs(i,i,mp,graph,visited,parent,source);
            }
        }

        // for(auto &it:mp){
        //     cout<<"Parent is "<<it.first<<":"<<endl;
        //     for(auto &j:it.second){
        //         cout<<j.first<<" "<<j.second<<endl;
        //     }
        //     cout<<endl;
        //     cout<<endl;
        // }

        int ans = 0;
        for(int i=0;i<target.size();i++){
            int p = parent[i];

            if(mp[p][target[i]] > 0){
                mp[p][target[i]]--;
            }
            else{
                ans++;
            }
        }



        return ans;
    }
};