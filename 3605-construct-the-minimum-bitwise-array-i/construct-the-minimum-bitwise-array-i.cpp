class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        //brute force will work fine 
        //if the second version comes tommoroow we wil work on it tommroow 
        vector<int>answer;
        for(auto &it:nums){
            if(it == 2)answer.push_back(-1);
            else {
                //when the number is in range 3 to 1000
                int x = 1;
                while(x < it && (x | (x+1)) != it){
                    x++;
                }
                //it means now x | x+1 == it
                answer.push_back(x);
            }
        }
        return answer;
    }
};