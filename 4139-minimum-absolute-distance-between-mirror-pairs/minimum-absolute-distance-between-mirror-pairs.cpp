class Solution {
public:
    string updated(string str) {
        reverse(str.begin(), str.end());
        int i = 0;
        while (i < str.length() && str[i] == '0') {
            i++;
        }
        str = str.substr(i);
        return str;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        long long size = nums.size(); long long ans = LLONG_MAX;
        unordered_map<string, long long> mp;

        for (int i = size - 1; i >= 0; i--) {
            string curr_str = to_string(nums[i]);
            string target = updated(curr_str);
            if (mp.find(target) != mp.end()) {
                ans = min(ans, abs(i - mp[target]));
            }
            mp[curr_str] = i;
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};