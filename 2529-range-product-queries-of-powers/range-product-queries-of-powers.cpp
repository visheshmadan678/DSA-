class Solution {
public:
    static const int mod = 1e9 + 7; // take the mod
    //code by vishu badmos
    //badmashi nahi mitar 
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> nums;
        for (int i = 0; i <= 31; i++) {
            if (n & (1 << i)) {
                nums.push_back(1 << i); // push that power  into the nums
            }
        }
        vector<int>ans;
        for(auto it:queries){
            int start = it[0], end = it[1]; // take the start point  and take the end point
            long long product = 1;
            for(int  i=start;i<=end;i++)product = (product * nums[i]) % mod;
            ans.push_back(product % mod);
        }
        return ans;
    }
};
