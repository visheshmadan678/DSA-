class Solution {
public:
    int minSteps(int n) {
        //answer is the sum of the prime factors 
        vector<int>ans;
        for(int i=2;i<=n;i++){
            while(n % i == 0){
                ans.push_back(i);
                n /= i; // change the value of n also
            }
        }
        if(ans.size() == 1)return ans[0];
        int sum = accumulate(ans.begin(),ans.end(),0);
        return sum;
    }
};