class Solution {
public:
    unordered_map<long long,long long>mp;
    int n;
    int dfs(int node, unordered_map<int,vector<int>>&adj, vector<int>&visited){
        visited[node] = 1; // mark as visited
        vector<int>score;
        for(auto &it:adj[node]){
            if(!visited[it])score.push_back(1+dfs(it,adj,visited));
        }
        long long sum = accumulate(score.begin(),score.end(),0);
        long long product = 1;
        for(auto &it:score)product *= it;
        long long upward = n - sum - 1;
        if(node!=0)mp[node] = upward * product; // push the score of the every node
        else mp[node] = product;
        return sum; // every node will return the sum of its subtrees
    }
    int countHighestScoreNodes(vector<int>& parents) {
       unordered_map<int,vector<int>>adj;
       n = parents.size();
       for(int i=0;i<parents.size();i++){
            if(parents[i]!=-1){
                adj[i].push_back(parents[i]);
                adj[parents[i]].push_back(i); //make adjcancy list
            }
       }
       vector<int>visited(parents.size(),0);
       dfs(0,adj,visited);
       long long maxi = LLONG_MIN;
       for(auto &it:mp)maxi = max(it.second,maxi);
       long long count = 0;
       for(auto &it:mp){
            if(it.second == maxi)count++;
        }
        return count; // return that count;
    }
};