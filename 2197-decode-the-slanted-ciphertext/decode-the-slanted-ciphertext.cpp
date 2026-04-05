class Solution {
public:
    string decodeCiphertext(string text, int rows) {

        if(text == "")return "";
        int len = text.length();
        int window_len = text.length() / rows;

        vector<vector<char>>matrix(rows,vector<char>(window_len,'_'));
        
        int i = 0;int row = 0; int col = 0;

        for(int i=0;i <= len - window_len;){
            string str = text.substr(i,window_len);
            for(auto &it:str){
                matrix[row][col] = it;
                col++;
            }
            col = 0;
            row++;
            i += window_len;
        }
        
        row = 0; col = 0;

        string ans = "";

        while(col < window_len){
            int col2 = col;
            while(row < rows && col2 < window_len){
                ans += matrix[row][col2];
                row++;
                col2++;
            }
            col++;
            row = 0;
        }

        int len2 = ans.length()-1;


        //removing the extra space from the back 
        while(ans[len2] == ' '){
            ans.pop_back();
            len2 = ans.length()-1;
        }

        return ans;
    }
};