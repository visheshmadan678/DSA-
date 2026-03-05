class Solution {
public:
    //code by vishu badmos
    //badmashi nahi mitar
    int minOperations(string s) {
        int ans = INT_MAX;

        // either i can start from the zero or either i can start from one
        bool flag = false; int val1 = 0; int val2 = 0;

        for(int i=0;i<s.length();i++){
            if((i % 2) != 0){
                // means i dont want zeroes on odd indexs
                if(s[i] == '0')val1++; // increase the value of val1 
                else val2++;
            }
            else{
                //on even indexes i only want zeroes 
                if(s[i] == '1')val1++;
                else val2++;
            }
        }

        //return the answer in the end
        ans = min(val1,val2);

        return ans;
    }
};