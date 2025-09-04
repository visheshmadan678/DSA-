class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>factors;
        for(int f=1;f*f<=n;f++){
            if(n%f!=0)continue;
            int f1 = f; int f2 = n / f1;
            factors.push_back(f1);
            if(f1!=f2)factors.push_back(f2);
        }
        sort(factors.begin(),factors.end());
        if(factors.size()<k)return -1;
        return factors[k-1];
    }
};