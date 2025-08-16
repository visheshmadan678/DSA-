class Solution {
public:
 int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size();
        long long lower = bounds[0][0], upper = bounds[0][1];
        long long diff = 0;

        for (int i = 0; i < n - 1; i++) {
            diff += (original[i + 1] - original[i]);
            lower = max((long long)bounds[i + 1][0] - diff, lower);
            upper = min((long long)bounds[i + 1][1] - diff, upper);
            if (lower > upper) return 0; // invalid range
        }
        return 1LL * (upper-lower+1);
 }
};