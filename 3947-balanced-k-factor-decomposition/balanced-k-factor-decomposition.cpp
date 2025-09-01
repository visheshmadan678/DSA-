class Solution {
public:
    vector<int> bestSubsequence;
    int bestDiff;

    void dfs(vector<int>& nums, int idx, int k, long long product, int n, vector<int>& current) {
        if ((int)current.size() == k) {
            if (product == n) {
                int diff = *max_element(current.begin(), current.end()) - 
                           *min_element(current.begin(), current.end());
                if (diff < bestDiff) {
                    bestDiff = diff;
                    bestSubsequence = current;
                }
            }
            return;
        }

        if (idx >= nums.size()) return;

        if (product * nums[idx] <= n) {
            current.push_back(nums[idx]);
            dfs(nums, idx, k, product * nums[idx], n, current); 
            current.pop_back();
        }

        dfs(nums, idx + 1, k, product, n, current);
    }

    vector<int> minDifference(int n, int k) {
        
        vector<int> nums;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                nums.push_back(i);
                if (i != n / i) nums.push_back(n / i);
            }
        }
        sort(nums.begin(), nums.end());

        bestDiff = INT_MAX;
        bestSubsequence.clear();

        vector<int> current;
        dfs(nums, 0, k, 1, n, current);

        return bestSubsequence;
    }
};
