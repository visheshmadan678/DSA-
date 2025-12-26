class Solution {
public:
    //code by vishu badmos
    //badmashi nahi mitar
    long long getDescentPeriods(vector<int>& prices) {
        int pointer = 0; int size = prices.size();
        long long ans = 0;
        while(pointer <  size){
            long long count = 0;
            while(pointer + 1 < size && prices[pointer+1] + 1 == prices[pointer]){
                count++;
                pointer++;
            }
            ans += ((count+1) * (count+2)) / 2;
            pointer++; // increase the pointer in the end
        }
        return ans;
    }
};