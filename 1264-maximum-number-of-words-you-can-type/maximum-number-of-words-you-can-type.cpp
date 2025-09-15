class Solution {
public:
    //code by vishu badmos 
    int canBeTypedWords(string text, string broke) {
        stringstream ss(text);
        string temp;
        vector<string>vec;
        while(ss>>temp){
            vec.push_back(temp);
        }
        int count = 0;
        for(auto &it:vec){
            bool flag = true;
            for(auto &j:it){
                if(broke.find(j) != string::npos){
                    flag = false;
                    break;
                }
            }
            if(flag)count++;
        }
        return count;
    }
};