class Solution {
public:
    int countHillValley(vector<int>& nums) {
        //one apporach can be creating a new vector and not taking the same elements or duplicates 
        vector<int>ans;
        for(auto it:nums){
            if(ans.empty() || ans.back()!=it){
                ans.push_back(it);
            }
        } 
        int size = ans.size();
        int cnt = 0;
        for(int i=1;i<=size-2;i++){
            if((ans[i]>ans[i-1] && ans[i]>ans[i+1]) || (ans[i]<ans[i+1] && ans[i]<ans[i-1]))
                cnt++;
        }
        return cnt;
    }
};