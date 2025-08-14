class Solution {
public:
    //code by vishu badmos
    string largestGoodInteger(string num) {
        string str = "";
        for(int i=0;i<=num.length()-3;i++){
            string temp = num.substr(i,3); // take a substring of length three
            if(temp[0]==temp[1] && temp[0]==temp[2]){
                str = max(str,temp);
            }
        }
        return str;
    }
};