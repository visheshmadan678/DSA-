class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size() == 1)return true;
        if(bits[bits.size()-2] == 0){
            if(bits[bits.size()-1] == 0)return true;
            else return false;
        }
        int i = 0;
        while(i < bits.size()){
            if(bits[i] == 0)i++;
            else if(bits[i] == 1)i+=2;

            if(i == bits.size()-1){
                return true; // if i some how managed to reach at this point 
            }
        }
        return false;
    }
};