class Solution {
public:
    int binaryGap(int n) {
        string str = bitset<32>(n).to_string(); // convert it into the string 
        
        if(n!=0){
            str.erase(0,str.find('1'));
        }
        else{
            str = "0";
        }

        int ans = INT_MIN;
        int size = str.length();
        //now find the adjacent ones 
        int left = 0; int right = 0;
        while(right < size){
            if(str[left] == '1'){
                right = left+1;
                while(right < size && str[right]!='1'){
                    right++; // increase the right pointer to the next one 
                }
                if(right < size && str[right] == '1')ans = max(ans,right-left);
                left = right;
            }
            else{
                left++;
            }
        }


        return ans == INT_MIN ? 0 : ans;
    }
};