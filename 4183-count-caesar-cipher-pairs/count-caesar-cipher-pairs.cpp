class Solution {
public:
    //code by vishu badmos 
    //badmashi nahi mitar
    long long countPairs(vector<string>& vec) {
        unordered_map<string, int> hash;
        long long size = vec.size();

        for (int i = 0; i < size; i++) {
            string a = vec[i];
            string temp = "";
            for (int j = 0; j < a.length() - 1; j++) {
                int x = a[j] - 'a';
                char y = a[j + 1] - 'a';
                if (x > y) {
                    temp += to_string(26 - x + y);
                } else {
                    temp += to_string(abs(x - y));
                }
            }
            hash[temp]++; // include the temp into the hash
        }

        long long ans = 0;
        for (auto& it : hash) {
            ans += (1LL * it.second) * 1LL * (it.second - 1) / 2;
        }

        return ans; 
    }
};