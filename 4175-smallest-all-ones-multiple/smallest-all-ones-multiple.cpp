class Solution {
public:
    int minAllOneMultiple(int k) {
        //even number can never be my answer for sure 
        if(k % 2 == 0)return -1;
        else if(k % 5 == 0)return -1; // if the k is divisble by number then it can be form a only one number 
        //the digits 1 3 7 and 9 can form 1 at the end
        int remain = 0;
        for(int i=1;i<=k;i++){
            remain = (remain * 10 + 1) % k;
            if(remain == 0)return i;
        }

        return -1;
    }
};