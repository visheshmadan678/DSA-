class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int>nums(n);
        for(int i=1;i<=n;i++){
            nums[i-1] = i;
        }
        k--;

        while(k){
            next_permutation(nums.begin(),nums.end());
            k--;
        }

        for(auto &it:nums)ans += to_string(it);
        return ans;
    }
};