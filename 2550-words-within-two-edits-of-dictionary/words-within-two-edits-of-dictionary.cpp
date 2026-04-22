class Solution {
public:

    bool check(string &a, string &b){
        int size = a.length(); // every one of them is having the equal length
        int i = 0; int count = 0;

        while(i < size){
            if(a[i] != b[i]){
                count++;
            }
            i++;
        }

        return count > 2 ? false : true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;

        for(auto &it:queries){
            string current = it;
            for(auto &j:dictionary){
                //match the current string with every other string in dictionary 
                bool flag = check(current,j);
                if(flag){
                    //if we find true // straight away break the loop
                    ans.push_back(current);
                    break;
                }
            }
        }

        return ans;
    }
};