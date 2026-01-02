class Solution {
public:
    long long maxPoints(vector<int>& arr1, vector<int>& arr2,int k) {
        long long size = arr1.size();

        long long sum1 = 0;
        for(auto &it:arr1){
            sum1 += 1LL * it;
        }

        long long sum2 = 0;
        for(auto &it:arr2){
            sum2 += 1LL * it;
        }

        priority_queue<long long, vector<long long>>qt; 

        for (long long i = 0; i < size; i++) {
            if(arr1[i] < arr2[i])qt.push(1LL * abs(arr1[i] - arr2[i]));
        }

        long long val = size - k;
        while (val && !qt.empty()) {
            sum1 += 1LL * qt.top();
            qt.pop();
            --val;
        }
        return sum1;
    }
};