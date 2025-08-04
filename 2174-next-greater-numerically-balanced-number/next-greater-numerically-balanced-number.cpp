class Solution {
public:
    //code by vishu badmos 
    //brute force is working fine badmashi nahi mitar
    bool valid(int num){
        //just check that number 
        string str = to_string(num);
        //i think the digits can be only 1 to 9 so i can iterate through an array of digits always 
        vector<int>digits(10,0);
        for(char &it:str){
            digits[it-'0']++; // just increase the amount
        }
        for(int i=0;i<10;i++){
            if(digits[i]!=0 && digits[i]!=i)return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        int i = n+1;
        while(true){
            if(valid(i)){
                return i;
                //just return true from here on the first valid part 
            }
            i++; // increase the i;
        }
        return 0;
    }
};