class Solution {
public:
    long long recursion(int i, vector<int>& unique, unordered_map<int, long long>& total, vector<long long>& dp) {
        if (i < 0) return 0;
        if (dp[i] != -1) return dp[i];

        long long not_take = recursion(i - 1, unique, total, dp);

        long long take = total[unique[i]];
        int j = i - 1;
        while (j >= 0 && unique[i] - unique[j] <= 2) j--;
        take += recursion(j, unique, total, dp);

        return dp[i] = max(take, not_take);
    }

    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> total;
        for (int val : power) total[val] += val;

        vector<int> unique;
        for (auto& p : total) unique.push_back(p.first);
        sort(unique.begin(), unique.end());

        int n = unique.size();
        vector<long long> dp(n, -1);

        return recursion(n - 1, unique, total, dp);
    }
};
