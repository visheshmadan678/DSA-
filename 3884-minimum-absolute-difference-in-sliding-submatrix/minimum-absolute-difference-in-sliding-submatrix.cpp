class Solution {
public:
    //brute force will work fine according to me
    //code by vishu badmos 
    // badmashi nahi mitar
    int find(int x, int y, vector<vector<int>>&grid,int k){
        set<int>st;
        for(int i =x;i < x + k; i++){
            for(int j = y; j < y + k; j++){
                st.insert(grid[i][j]);
            }
        }

        if(st.size() == 1)return 0;

        int min_diff = INT_MAX;
        int prev = -1000000;
        for(auto &it:st){
            if(prev == -1000000){
                prev = it;
            }else{
                int current = it;
                int diff = it - prev;
                cout<<diff<<endl;
                min_diff = min(min_diff,diff);
                prev = current; // update the value of previous
            }
        }

        return min_diff;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>>answer;

        for(int i=0;i <= (m - k);i++){
            vector<int>temp;
            for(int j=0;j <= (n-k);j++){
                if(k > 1)temp.push_back(find(i,j,grid,k));
                else{
                    temp.push_back(0);
                }
            }
            answer.push_back(temp);
        }

        return answer;
    }
};