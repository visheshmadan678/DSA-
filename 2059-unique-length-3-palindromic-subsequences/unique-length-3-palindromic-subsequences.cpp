#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        // prefix[i][c] = count of char 'a' + c in s[0..i]
        // suffix[i][c] = count of char 'a' + c in s[i..n-1]
        vector<array<int, 26>> prefix(n), suffix(n);

        array<int, 26> cnt{};
        cnt.fill(0);

        // Build prefix
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
            prefix[i] = cnt;
        }

        // Build suffix
        cnt.fill(0);
        for (int i = n - 1; i >= 0; i--) {
            cnt[s[i] - 'a']++;
            suffix[i] = cnt;
        }

        // Use an unordered_set<int> to store unique palindromes
        // Encode each palindrome "x y x" as key = (x_index * 26 + y_index)
        unordered_set<int> st;

        for (int i = 1; i <= n - 2; i++) {
            int mid = s[i] - 'a';  // middle character index

            for (int j = 0; j < 26; j++) {
                if (prefix[i - 1][j] > 0 && suffix[i + 1][j] > 0) {
                    int key = j * 26 + mid; // encode (outer_char, mid_char)
                    st.insert(key);         // duplicates auto-ignored
                }
            }
        }

        return (int)st.size();
    }
};
