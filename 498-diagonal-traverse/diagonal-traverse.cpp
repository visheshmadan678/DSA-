class Solution {
public:
    vector<int>answer;
    bool flag = false;
    void traverse(pair<int,int>&it,vector<vector<int>>& mat){
        vector<int>ds;
        int i = it.first;
        int j = it.second;
        int n = mat.size();
        while(i<n && j>=0){
            ds.push_back(mat[i][j]);
            i++;
            j--;
        }

        if(flag){
            reverse(ds.begin(),ds.end());
            for(auto it:ds){
                answer.push_back(it);
            }
            flag = false;
        }
        else{
            for(auto it:ds){
                answer.push_back(it);
            }
            flag = true;
        }

    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        //lets fill the elements which are only to be traversed 
        // that would be the border elements of row i =0 and column j = n-1;
        int n = mat.size();
        int m = mat[0].size();

        
        //making a vector of all the elements to be traversed 
        vector<pair<int,int>>elements;

        for(int i=1;i<mat[0].size();i++){
            elements.push_back({0,i});
        }//pushing the first row
        
        answer.push_back(mat[0][0]);
        
        for(int i=1;i<mat.size()-1;i++){
            elements.push_back({i,m-1});
        }

        

        for(auto it:elements){
            traverse(it,mat);
        }

        if(n!=1)answer.push_back(mat[n-1][m-1]);
        return answer;
    }
};