class Solution {
public:
    //code by vishu badmos
    //badmashi nahi mitar
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size(); 
        int col = matrix[0].size();
        int ans = INT_MIN;

        vector<vector<int>>grid(row,vector<int>(col,0));
        for(int i = 0; i<row;i++){
            if(matrix[i][col-1] == '1'){
                grid[i][col-1] = 1;
            }
            else{
                grid[i][col-1] = 0;
            }
        }

        for(int i=0;i<row;i++){
            for(int j = col-2;j>=0;j--){
                if(matrix[i][j] == '1'){
                    grid[i][j] = 1 + grid[i][j+1]; 
                }
                else{
                    grid[i][j] = 0;
                }
            }
        }

        for(auto &it:grid){
            for(auto &k:it)cout<<k<<" ";
            cout<<endl;
        }


        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == '1'){
                    int right_margin = INT_MAX;
                    for(int k = i; k < row; k++){
                        right_margin = min(grid[k][j],right_margin);
                        ans = max(ans,(abs(k-i)+1) * right_margin);
                    }
                }
            }
        }

        return (ans == INT_MIN) ? 0 : ans;
    }
};