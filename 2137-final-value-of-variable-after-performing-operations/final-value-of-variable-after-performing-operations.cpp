class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(auto &it:operations){
            if(it == "--X" || it == "X--"){
                x -= 1;
            }
            else{
                x += 1;
            }
        }
        return x;
    }
};