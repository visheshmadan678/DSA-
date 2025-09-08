class Solution {
public:
    bool check(int a,int b){
        string str1 = to_string(a);
        string str2 = to_string(b); // convert both of them into the string
        for(auto it:str1)if(it=='0')return false;
        for(auto it:str2)if(it=='0')return false;
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int start = 1;
        for(int i=start;i<=n/2;i++){
            if(check(i,n-i))return {i,n-i};
        }
        return {};
    }
};