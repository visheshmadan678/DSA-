class Solution {
public:
    bool check(int idx, int k, string s, vector<int>& order) {
        for (int i = 0; i <= idx; i++) {
            s[order[i]] = '*';
        }

        int n = s.size();
        long long total = 1LL * n * (n + 1) / 2;

        long long nostar = 0, len = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                nostar += 1LL * len * (len + 1) / 2;
                len = 0;
            } else {
                len++;
            }
        }
        nostar += 1LL * len * (len + 1) / 2;

        long long withstar = total - nostar;
        return withstar >= k;
    }

    int minTime(string s, vector<int>& order, int k) {
        int left = 0, right = order.size() - 1;
        int idx = INT_MAX;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid, k, s, order)) {
                idx = min(idx, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return idx == INT_MAX ? -1 : idx;
    }
};
