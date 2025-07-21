class Solution {
public:
    string makeFancyString(string s) {
       //think of a more simpler way for this code 
       int cnt = 0;
       string temp = "";
       temp.push_back(s[0]); // inserting the first character 
       for(int i=1;i<s.length();i++){
            if(temp.back()==s[i] && cnt>=1)continue;
            else if(temp.back()==s[i]){
                temp.push_back(s[i]);
                cnt++;
            }
            else{
                temp.push_back(s[i]);
                cnt = 0;
            }

        }

       return temp;
    }
};