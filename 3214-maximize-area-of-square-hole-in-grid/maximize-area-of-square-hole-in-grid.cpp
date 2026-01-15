class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hbars,vector<int>& vbars) {
        map<pair<long long, long long>, int> mp;
        for (int i = 0; i < hbars.size(); i++) {
            for (int j = 0; j < vbars.size(); j++) {
                pair<long long, long long> pt = {hbars[i], vbars[j]};
                mp[pt]++;
            }
        }

        long long ans = 1;

        for (auto& it : mp) {
            long long count = 1;
            long long x = it.first.first;
            long long y = it.first.second;
            while (mp.find({x + 1, y + 1}) != mp.end()) {
                count++;
                x = x + 1;
                y = y + 1;
            }
            ans = max(ans, count);
        }

        return (ans+1)*(ans+1);
    }
};