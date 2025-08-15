class Solution {
public:
    bool isPrime(long long num) {
        if (num <= 1) return false;
        for (long long i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        vector<long long> primes;

        for (int i = 0; i < s.length(); i++) {
            long long num = 0;
            for (int j = i; j < s.length(); j++) {
                num = num * 10 + (s[j] - '0');

                // Stop if num exceeds LLONG_MAX/10 safety check
                if (num < 0) break; 

                if (isPrime(num)) {
                    primes.push_back(num);
                }
            }
        }

        if (primes.empty()) return 0;

        sort(primes.begin(), primes.end());
        primes.erase(unique(primes.begin(), primes.end()), primes.end());

        if (primes.size() < 3) {
            return accumulate(primes.begin(), primes.end(), 0ll);
        }

        int m = primes.size();
        return primes[m - 1] + primes[m - 2] + primes[m - 3];
    }
};
