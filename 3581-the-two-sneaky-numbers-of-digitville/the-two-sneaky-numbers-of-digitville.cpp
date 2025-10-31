class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int>st;
        vector<int>ans;
        for(auto &it:nums){
            if(st.count(it) == 0){
                st.insert(it);
            }
            else{
                ans.push_back(it);
            }
        }
        return ans;
    }
};