class Solution {
public:
    //code by vishu badmos 
    //badmashi nahi mitar 
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        //if k  == 1 it means the answer will always be true
        if(k == 1)return true; // as the answer always 
        set<int>st;
        int n = nums.size();
        for(int i=0;i <= n-k ;i++){
            int j = i + 1;
            bool flag = false;
            for(;j < i + k; j++){
                if(nums[j] > nums[j-1]){
                    flag = true;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                //store that index into our set 
                st.insert(i); // it means this is a valid index 
            }
        }

        for(auto &it:st){
            if(st.count(it + k))return true;
        }
        return false;
    }
};