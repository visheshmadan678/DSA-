class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        //one i need a normal prefix sum
        //another i need prefix and suffix sum of the basis of strategy !!
        int size = prices.size();
        long long ans = LLONG_MIN;
        vector<long long>prefix(size);
        prefix[0] = prices[0];
        //this will create the normal prefix sum
        for(int i=1;i<size;i++){
            prefix[i] = prices[i] + prefix[i-1];
        }

        //now the prefix sum on the basis of strategy
        vector<long long>prefix_s(size);
        vector<long long>suffix_s(size);

        if(strategy[0] == 1)prefix_s[0] = prices[0];
        else if(strategy[0] == -1)prefix_s[0] = -prices[0];
        else prefix_s[0] = 0;

        for(int i=1;i<size;i++){
            if(strategy[i] == 1){
                prefix_s[i] = prefix_s[i-1] + prices[i]; // then add the value 
            }
            else if(strategy[i] == -1){
                prefix_s[i] = prefix_s[i-1] - prices[i]; // remove that stock value
            }
            else {
                prefix_s[i] = prefix_s[i-1]; // same as it is
            }
        }

        if(strategy[size-1] == 1)suffix_s[size-1] = prices[size-1];
        else if(strategy[size-1] == -1)suffix_s[size-1] = -prices[size-1];
        else suffix_s[size-1] = 0;

        for(int i=size-2;i>=0;i--){
            if(strategy[i] == 1){
                suffix_s[i] = suffix_s[i+1] + prices[i]; // then add the value 
            }
            else if(strategy[i] == -1){
                suffix_s[i] = suffix_s[i+1] - prices[i]; // remove that stock value
            }
            else {
                suffix_s[i] = suffix_s[i+1]; // same as it is
            }
        }


        for(int i=0;i+k<=size;i++){
            int left = i; // left border
            int right = i+k-1;  // right border
            long long lsum = 0; long long rsum = 0;
            if(left-1>=0){
                //then only i have include the other value
                lsum =  prefix_s[left-1];
            }
            if(right + 1 < size){
                //then only i can take the contribution for this
                rsum =  suffix_s[right+1];
            }
            //now i have take the contribution of k/2 on the right half of the array 
            int low = i + (k/2) - 1;
            int high = i + k - 1;
            ans = max(ans,prefix[high]-prefix[low]+lsum+rsum);
        }


        long long fsum = 0;
        for(int i=0;i<size;i++){
            if(strategy[i] == 1){
                fsum += prices[i];
            }
            else if(strategy[i] == -1){
                fsum -= prices[i];
            }
        }
        
        ans = max(ans,fsum);
        return ans;
    }
};