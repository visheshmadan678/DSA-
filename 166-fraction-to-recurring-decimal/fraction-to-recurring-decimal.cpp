class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string result;

        // handle sign
        if ((numerator < 0) ^ (denominator < 0)) result += "-";

        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        // integer part
        result += to_string(n / d);
        long long rem = n % d;
        if (rem == 0) return result; // no fractional part

        result += ".";
        unordered_map<long long, int> seen; // remainder -> position in string

        while (rem != 0) {
            if (seen.count(rem)) {
                // repeating cycle detected
                result.insert(seen[rem], "(");
                result += ")";
                break;
            }
            seen[rem] = result.size();
            rem *= 10;
            result += to_string(rem / d);
            rem %= d;
        }

        return result;
    }
};
