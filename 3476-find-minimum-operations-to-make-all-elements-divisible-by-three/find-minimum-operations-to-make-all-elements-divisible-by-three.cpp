class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        //we have to find the closest multiple of three from every number in our array 
        long long  ans = 0;
        for(auto &it:nums){
            if((it % 3) == 0)continue;
            else{
                int a = it / 3; int b = a + 1;
                int op =  min(it-(3 *a),(3*b)-it);
                ans += op;
            }
        }
        return ans;
    }
};