class Solution {
public:
    bool check(int length, string &s) {
        int n = s.size();
        if (n % length != 0) return false;

        // map of frequency for the first window
        unordered_map<char,int> ref;
        for (int i = 0; i < length; i++) {
            ref[s[i]]++;
        }

        // check every next window
        for (int i = length; i < n; i += length) {
            unordered_map<char,int> curr;
            for (int j = i; j < i + length; j++) {
                curr[s[j]]++;
            }
            if (curr != ref) return false; // window differs
        }
        return true;
    }

    int minAnagramLength(string s) {
        int len = s.length();
        vector<int> factors;

        // find all factors in O(√n)
        for (int f = 1; f * f <= len; f++) {
            if (len % f != 0) continue;
            factors.push_back(f);
            if (f != len / f) factors.push_back(len / f);
        }

        int ans = INT_MAX;
        for (auto it : factors) {
            if (check(it, s)) ans = min(ans, it);
        }

        return ans;
    }
};
