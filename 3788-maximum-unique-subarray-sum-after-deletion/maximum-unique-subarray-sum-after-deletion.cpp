class Solution {
public:
    int maxSum(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int ans = 0;
        unordered_set<int>st;
        for(auto it:nums){
            if(it>0 && st.count(it)==0){
                ans += it;
                st.insert(it);
            } 
        }
        //if it in the end the ans = 0; 
        //that means no positive was found it means all were zero or all were negative 
        if(ans==0){
        int mini = INT_MIN;
        for(auto it:nums){
            if(it<=0)mini = max(mini,it);
        }
        
        if(mini==0)return 0;
        if(mini<0)return mini;
        }

        return ans;
    }
};