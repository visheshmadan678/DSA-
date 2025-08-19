class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = INT_MIN;
        for (int i = 0; i <= (int)arr.size() - 3; i++) {
            for (int j = i + 1; j <= (int)arr.size() - 2; j++) {
                int prev = j; 
                int sum = arr[i] + arr[j];
                int take = 2;
                for (int k = j + 1; k < (int)arr.size(); k++) { 
                    if (arr[k] == sum) {
                        take++;
                        sum = arr[prev] + arr[k];
                        prev = k;
                    }
                }
                ans = max(ans, take);
            }
        }
        return ans==2?0:ans;
    }
};
