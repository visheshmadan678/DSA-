class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<long long, long long> mp;

        for (auto& it : nums)
            mp[it]++; // update the map

        long long n = nums.size() / 2;

        for (auto& it : mp) {
            if (it.second == n) {
                return it.first;
            }
        }

        return 0;
    }
};