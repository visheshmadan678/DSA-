class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size(); // store the indices 

        for(int i=0;i<n;i++){
            for(int j=m-2;j>=0;j--){
                if(mat[i][j]==1){
                    mat[i][j] += mat[i][j+1]; // store the plus one as answer 
                }
            }
        }

        int count  = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //go to every point 
                int width = INT_MAX;
                for(int k=i;k<n;k++){
                    width = min(width,mat[k][j]);
                    count += width;
                }
            }
        }

        return count;
    }
};