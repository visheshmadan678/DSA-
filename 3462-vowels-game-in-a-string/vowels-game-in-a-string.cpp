class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0; // this count to store the count of the vowels 
        for(auto it:s){
            if(it=='a' || it=='e' || it=='o' || it=='u' || it=='i'){
                count++;
            }
        }
        if(count==0)return false;

        return true;
    }
};