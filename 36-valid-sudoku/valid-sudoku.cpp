class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //lets check for the all rows first 
        unordered_map<int,int>mp;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int ele = board[i][j];
                if(ele=='.')continue;
                if(mp.find(ele)==mp.end()){
                    mp[ele]++;
                }
                else{
                    return false;
                }
            }
            //jaise hi ek row khatam hoyegi we will clear the  mp for the next rown
            mp.clear();
        }

        //doing the same for the colums 
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int ele = board[j][i];
                if(ele=='.')continue;
                if(mp.find(ele)==mp.end()){
                    mp[ele]++;
                }
                else{
                    return false;
                }
            }
            //jaise hi ek column khatam ho jayega start for the next column
            mp.clear();
        }

        //now we have to check for all the boxes 
        //toh bhkchodi krne ke liye i will use 9 for loops kyuki mera man hai 
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int ele = board[i][j];
                if(ele=='.')continue;
                if(mp.find(ele)==mp.end())mp[ele]++; // ya toh nhi milega 
                else return false; // ya toh milega
            }
        }

        mp.clear();

        for(int i=0;i<3;i++){
            for(int j=3;j<6;j++){
                int ele = board[i][j];
                if(ele=='.')continue;
                if(mp.find(ele)==mp.end())mp[ele]++; // ya toh nhi milega 
                else return false; // ya toh milega
            }
        }

        mp.clear();

        for(int i=0;i<3;i++){
            for(int j=6;j<9;j++){
                int ele = board[i][j];
                if(ele=='.')continue;
                if(mp.find(ele)==mp.end())mp[ele]++; // ya toh nhi milega 
                else return false; // ya toh milega
            }
        }

        mp.clear();

        for(int i=3;i<6;i++){
            for(int j=0;j<3;j++){
                int ele = board[i][j];
                if(ele=='.')continue;
                if(mp.find(ele)==mp.end())mp[ele]++; // ya toh nhi milega 
                else return false; // ya toh milega
            }
        }
        mp.clear();

        for(int i=3;i<6;i++){
            for(int j=3;j<6;j++){
                int ele = board[i][j];
                if(ele=='.')continue;
                if(mp.find(ele)==mp.end())mp[ele]++; // ya toh nhi milega 
                else return false; // ya toh milega
            }
        }
        mp.clear();

        for(int i=3;i<6;i++){
            for(int j=6;j<9;j++){
                int ele = board[i][j];
                if(ele=='.')continue;
                if(mp.find(ele)==mp.end())mp[ele]++; // ya toh nhi milega 
                else return false; // ya toh milega
            }
        }
        mp.clear();

        for(int i=6;i<9;i++){
            for(int j=0;j<3;j++){
                int ele = board[i][j];
                if(ele=='.')continue;
                if(mp.find(ele)==mp.end())mp[ele]++; // ya toh nhi milega 
                else return false; // ya toh milega
            }
        }

        mp.clear();

        for(int i=6;i<9;i++){
            for(int j=3;j<6;j++){
                int ele = board[i][j];
                if(ele=='.')continue;
                if(mp.find(ele)==mp.end())mp[ele]++; // ya toh nhi milega 
                else return false; // ya toh milega
            }
        }

        mp.clear();

        for(int i=6;i<9;i++){
            for(int j=6;j<9;j++){
                int ele = board[i][j];
                if(ele=='.')continue;
                if(mp.find(ele)==mp.end())mp[ele]++; // ya toh nhi milega 
                else return false; // ya toh milega
            }
        }

        return true;
    }
};