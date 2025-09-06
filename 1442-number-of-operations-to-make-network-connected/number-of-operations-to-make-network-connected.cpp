class Solution {
public:
    void dfs(int node, vector<vector<int>>&adjlist,vector<int>&visited){
        visited[node] = 1;
        for(auto it:adjlist[node]){
            if(!visited[it]){
                dfs(it,adjlist,visited);
            }
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges<n-1)return -1;
        vector<vector<int>>adjlist(n);
        for(auto it:connections){
            int u = it[0];
            int v = it[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u); 
        }
        vector<int>visited(n,0);
        cout<<visited.size()<<endl;
        int count = 0;
        int extra = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adjlist,visited); 
                count++; // count the connected components
            }
        }
        
        //hamare pass cables ki count hai connected components ki count hai hai 
        return count-1;
    }
};