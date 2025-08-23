class Solution {
public:
    bool isValid(string s) {
        string temp = "";
        for(auto it:s){
            temp.push_back(it);
            //if the last three charcters of the temp form a string abc then remove it 
            int size = temp.size();
            if(temp.size()>=3){
            int a = temp[size-1];
            int b = temp[size-2];
            int c = temp[size-3];
            if(a=='c' && b=='b' && c =='a'){
                temp.pop_back();
                temp.pop_back();
                temp.pop_back(); 
            }
            }
        }

        if(temp.empty())return true;

        return false;
    }
};