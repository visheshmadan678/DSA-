class Solution {
public:
    string perform_operation(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string curr = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';

            curr.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        reverse(curr.begin(), curr.end());
        return curr;
    }
    string multiply(string a, string b) {
        if(a == "0" || b == "0")return "0";
        string ans = "";
        vector<string> vec;

        int lenmin = min(a.length(), b.length());
        int lenmax = max(a.length(), b.length());

        bool flag = (lenmin == a.length());

        int counter = 0;

        for (int i = lenmin - 1; i >= 0; i--) {
            int carry = 0;
            string temp = "";

            for (int j = lenmax - 1; j >= 0; j--) {
                int fix_digit, var_digit;

                if (flag) {
                    fix_digit = a[i] - '0';
                    var_digit = b[j] - '0';
                } else {
                    fix_digit = b[i] - '0';
                    var_digit = a[j] - '0';
                }

                int prod = fix_digit * var_digit + carry;
                temp.push_back((prod % 10) + '0');
                carry = prod / 10;
            }

            if (carry > 0)
                temp.push_back(carry + '0');

            reverse(temp.begin(), temp.end());
            temp.append(counter, '0');

            vec.push_back(temp);
            counter++;
        }

        // now i just have to add these strings
        int size = vec.size();
        for (auto& it : vec)
            cout << it << endl;

        for (int i = 0; i < vec.size(); i++) {
            ans = perform_operation(ans, vec[i]);
        }

        
        return ans;
    }
};