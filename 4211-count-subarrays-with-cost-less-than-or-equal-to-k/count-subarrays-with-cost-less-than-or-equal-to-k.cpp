class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        multiset<long long>st; long long left = 0; long long right = 0; long long ans = 0;
        while(right < nums.size()){
            st.insert(nums[right]);
            while(left < nums.size() && ((*st.rbegin() - *st.begin()) * ((right-left)+1)) > k){
                st.erase(st.find(nums[left]));
                left++;
            }
            ans += (right-left)+1;
            right++;
        }
        return ans;
    }
};