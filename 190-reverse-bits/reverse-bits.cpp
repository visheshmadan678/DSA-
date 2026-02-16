class Solution {
public:
    string int_to_binary(int a) {
        string str = "";
        while (a) {
            if (a % 2 == 0)
                str.push_back('0');
            else
                str.push_back('1');
            a /= 2;
        }

        return str;
    }

    int reverseBits(int a) {
        string str = int_to_binary(a);
        int size = str.length();
        int ans = 0;

        if (str.length() != 32) {
            while (str.length() != 32) {
                str.push_back('0');
            }
        }

        for (int i = 32; i >= 0; i--) {
            if (str[i] == '1')
                ans += pow(2, 32 - i - 1);
        }

        return ans;
    }
};