class Solution {
public:
    bool check(int n) {
        string str = to_string(n);
        string num = "";

        unordered_map<char, char> mp = {{'0', '0'}, {'1', '1'}, {'8', '8'},
                                        {'2', '5'}, {'5', '2'}, {'6', '9'},
                                        {'9', '6'}};

        for (auto& it : str) {
            if (mp.find(it) == mp.end()) {
                return false;
            }

            num += mp[it];
        }

        return num != str;
    }
    int rotatedDigits(int n) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (check(i)) {
                count++;
            }
        }

        return count;
    }
};