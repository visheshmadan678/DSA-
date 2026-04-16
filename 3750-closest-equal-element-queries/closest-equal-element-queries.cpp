class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {
            int idx = queries[i];
            int val = nums[idx];

            vector<int> &positions = mp[val];

            if (positions.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            auto lb_it = lower_bound(positions.begin(), positions.end(), idx);
            auto ub_it = upper_bound(positions.begin(), positions.end(), idx);

            int lb;
            if (lb_it == positions.begin()) {
                lb = positions.back(); 
            } else {
                lb = *(lb_it - 1);
            }

            int ub;
            if (ub_it == positions.end()) {
                ub = positions[0]; 
            } else {
                ub = *ub_it;
            }

            int dist1 = abs(idx - lb);
            dist1 = min(dist1, n - dist1);

            int dist2 = abs(idx - ub);
            dist2 = min(dist2, n - dist2);

            ans.push_back(min(dist1, dist2));
        }

        return ans;

    }
};