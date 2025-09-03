class Solution {
public:
    //code by vishu badmos
    //badmash nahi mitar
    long long recursion(vector<vector<int>>&adjlist,vector<int>&visited,int node){
        int count = 0;

        visited[node] = 1; // mark the node as visited

        for(auto it:adjlist[node]){
            int neighbour = it; // the adjacent node
            if(!visited[neighbour]){
                count += (1+recursion(adjlist,visited,neighbour));
            }
        }

        return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjlist(n);
        vector<int>visited(n,0);
        for(auto &it:edges){
            int u = it[0]; //source 
            int v = it[1]; // destination 
            adjlist[u].push_back(v);
            adjlist[v].push_back(u); // make a bidirectional connection
        }
        vector<long long>counts;
        for(int i=0;i<n;i++){
            //iterate through all the nodes
            if(!visited[i]){
                counts.push_back(1+recursion(adjlist,visited,i)); // pass the node also 
            }
        }

        //now i have all the count of all the connected componenets 
        long long sum = counts[counts.size()-1]; 
        long long ans = 0;
        for(int i=counts.size()-2;i>=0;i--){
            int curr = counts[i];
            ans += curr * sum;
            sum += counts[i];
        }


        return ans;
    }
};