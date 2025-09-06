class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>indegree(n,0); // mark everyone as zero in the starting 

        for(auto it:roads){
            int u = it[0];  //source
            int v = it[1];  //destination
            indegree[u]++; // increase the indegree of both of them
            indegree[v]++; // increase the indegree of both of them
        }

        sort(indegree.rbegin(),indegree.rend());
        long long sum  = 0;
        for(auto it:indegree){
            sum += 1LL * n * it;
            n--;
        }

        return sum;
    }
};