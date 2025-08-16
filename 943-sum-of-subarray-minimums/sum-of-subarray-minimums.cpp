class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
         int n = nums.size();
    const int MOD = 1e9 + 7;

    stack<int> st;
    vector<int> next_smaller(n, n);   
    vector<int> prev_smaller(n, -1);  
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[i] < nums[st.top()]) {
            int idx = st.top();
            next_smaller[idx] = i;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[i] <= nums[st.top()]) {
            int idx = st.top();
            prev_smaller[idx] = i;
            st.pop();
        }
        st.push(i);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long left = i - prev_smaller[i];
        long long right = next_smaller[i] - i;
        ans = (ans + (long long)nums[i] * left % MOD * right % MOD) % MOD;
    }

    
    return (int)ans;
    }
};