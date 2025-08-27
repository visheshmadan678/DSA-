class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size();  int m = grid[0].size(); // store the sizes 
        unordered_map<int,int>mpr; // one hash map for the row
        unordered_map<int,int>mpc; // one hash map for the column

        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)cnt++;
            }
            mpr[i] = cnt; // store the count into the map with row
        }

        for(int j=0;j<m;j++){
            int cnt = 0; // declare a count for every colums
            for(int i=0;i<n;i++){
                if(grid[i][j]==1)cnt++; // increase the count
            }
            mpc[j] = cnt;
        }


        long long ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    //if we got a one // we have to count the triangles it can form in his column and in his row 
                    if(mpr[i]>0 && mpc[j]>0){
                        ans += (mpr[i]-1) * (mpc[j]-1);
                    }
                }
            }
        }

        return ans;   //return that answer at the end of the day 
    }
};