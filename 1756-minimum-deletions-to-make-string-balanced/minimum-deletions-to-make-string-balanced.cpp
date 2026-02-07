class Solution {
public:
    int minimumDeletions(string a) {
        int size = a.length();
        int ans = INT_MAX;

        if(size == 1)return 0; // the base case

        vector<int> prefix_b(size);
        vector<int> suffix_a(size);

        if (a[0] == 'b') {
            prefix_b[0] = 1;
        } else {
            prefix_b[0] = 0;
        }

        for (int i = 1; i < a.length(); i++) {
            if (a[i] == 'b') {
                prefix_b[i] = 1 + prefix_b[i - 1];
            } else {
                prefix_b[i] = prefix_b[i - 1];
            }
        }

        if (a[size - 1] == 'a') {
            suffix_a[size - 1] = 1;
        } else {
            suffix_a[size - 1] = 0;
        }

        for (int i = size - 2; i >= 0; i--) {
            if (a[i] == 'a') {
                suffix_a[i] = 1 + suffix_a[i + 1];
            } else {
                suffix_a[i] = suffix_a[i + 1];
            }
        }

        for (int i = 0; i < size - 1; ++i) {
            ans = min(ans, prefix_b[i] + suffix_a[i + 1]);
        }

        ans = min(ans,suffix_a[0]);
        ans = min(ans,prefix_b[size-1]);

        return ans;
    }
};