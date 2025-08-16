class Solution {
public:
    int maximum69Number (int num) {
        //so the main part is implementaton 
        //code by vishu badmos 
        //whenver the first six will hit we will change it to 9 
        string str =  to_string(num);
        for(int i=0;i<str.length();i++){
            if(str[i]=='6'){
                str[i]= '9';
                break;
            }
        }
        return stoi(str);
    }
};