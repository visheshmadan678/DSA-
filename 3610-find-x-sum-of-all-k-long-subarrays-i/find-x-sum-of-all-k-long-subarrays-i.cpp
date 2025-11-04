class Solution {
public:
    int solve(int index, int k, int x, const vector<int>& nums){
        int sum = 0;
        unordered_map<int,int> freq;
        unordered_map<int,long long> sm;
        int n = nums.size();

        for(int i = index; i < index + k && i < n; ++i){
            freq[nums[i]]++;
            sm[nums[i]] += nums[i];
        }

        vector<int> op;
        op.reserve(freq.size());
        for (auto &p : freq) op.push_back(p.first);

        sort(op.begin(), op.end(), [&freq](int a, int b){
            if (freq[a] != freq[b]) return freq[a] > freq[b];
            return a > b;
        });

        int taken = 0;
        for (int v : op){
            if (taken >= x) break;
            sum += sm[v]; 
            ++taken;
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        if (k <= 0 || n == 0) return ans;
        if (k > n) k = n;

        for(int i = 0; i <= n - k; ++i){
            ans.push_back(solve(i, k, x, nums));
        }
        return ans;
    }
};
