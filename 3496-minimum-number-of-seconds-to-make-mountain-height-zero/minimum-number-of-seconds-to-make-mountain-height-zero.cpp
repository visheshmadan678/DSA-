class Solution {
public:
     bool check(long long mid, long long height, vector<int>& workers) {
        long long h = 0;
        for (auto &it : workers) {
            long long curr_time = it;
            long long exp = 2 * (mid / curr_time);
            long long n = 1;
            while ((1LL * n * n + n) <= exp) {
                n++;
            }
            h += (n - 1);
            if (h >= height) return true; // small optimization
        }
        return h >= height;
    }
    long long minNumberOfSeconds(int he, vector<int>& workers) {
   long long h = he;
        long long low = 1;
        long long maxi = *max_element(workers.begin(), workers.end());
        long long high = 1LL * maxi * (1LL * h * (h + 1)) / 2; // worst case bound
        long long ans = LLONG_MAX;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (check(mid, h, workers)) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};