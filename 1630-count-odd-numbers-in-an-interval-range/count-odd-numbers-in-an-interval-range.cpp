class Solution {
public:
    int countOdds(int low, int high) {
        // obviously we will not go for the linear approach to solve this question 
        // we have to find a method directly for this
        if(low == high){
            if(low % 2 == 0)return 0;
            return 1;
        }
        int count = 0;
        if(low % 2 == 0 && high % 2 == 0){
            //jab dono odd hai toh yeh wala case 
            count += (high - low - 1) / 2 + 1; 
        }
        else if(low % 2 == 0 || high % 2 == 0){
            // jab dono mein se ek even hai ek odd hai 
            count += (high - low -1) / 2 + 1;
        }
        else{
            //jab dono hi odd hai
            count += (high - low -1) / 2 + 2;
        }

        return count;
    }
};