class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();
        vector<int> dp(n, 1);
        vector<pair<int,int>> buildings;

        for(int i = 0; i < n; i++) {
            buildings.push_back({arr[i], i});
        }

        sort(buildings.rbegin(), buildings.rend());
        int ans = 1;

        for(auto &it : buildings) {
            int idx = it.second;

            for(int j = idx - 1; j >= max(0, idx - d); j--) {
                if(arr[j] >= arr[idx]) break;
                dp[j] = max(dp[j], dp[idx] + 1);
                ans = max(ans, dp[j]);
            }

            for(int j = idx + 1; j <= min(n - 1, idx + d); j++) {
                if(arr[j] >= arr[idx]) break;
                dp[j] = max(dp[j], dp[idx] + 1);
                ans = max(ans, dp[j]);
            }
        }

        return ans;
    }
};