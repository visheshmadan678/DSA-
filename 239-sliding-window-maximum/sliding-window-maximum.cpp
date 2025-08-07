class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN; int idx = -1;
        //code by vishu badmos 
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]>=maxi){
                maxi = nums[i];
                idx = i; // change the value of the index
            }
            
            if(i>=k-1){
                ans.push_back(maxi); // push the maxi into the answer 
                if(idx == i - k +1){
                    //if the max element was located at the start position of our array 
                    int k = idx+1;
                    maxi = INT_MIN;
                    while(k<=i){
                        if(maxi<=nums[k]){
                            maxi = nums[k];
                            idx = k;
                        }
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};