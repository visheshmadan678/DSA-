class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        long long ans = 0;
         for(int i:nums){
            int best = i; 
            for(int d = 1; d * d <= i; d++){
                if(i % d == 0){
                    if(st.count(d)){
                        best = min(best,d);
                    }
                    int other = i / d;
                    if(st.count(other)){
                        best = min(best,other);
                    }
                }
            }
            ans += best;
        }
        return ans;
    }
};