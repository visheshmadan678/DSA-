class Solution {
public:
    int binary_search(int idx, long long  target, int &size,vector<int>&nums){
        int ans = -1;int high = size-1; int low = idx;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                return mid;
            }

            if(target < nums[mid]){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int size = nums.size();        
        for(int i=0;i<size-3;i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<size-2;j++){
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                //now take 2 pointers k and l and k will start from j +1 and l will be at the end of the array 
                for(int k = j+1;k<size-1;k++){
                    if (k > j + 1 && nums[k] == nums[k-1]) continue;
                    long long  new_target = 1LL * (target - (1ll* (1LL * (nums[i] + nums[j]) + nums[k])));
                    int idx = binary_search(k+1,new_target,size,nums);
                    if(idx!=-1){
                        //push it into the answer
                        ans.push_back({nums[i],nums[j],nums[k],nums[idx]});
                    }
                }
            }
        }
        return ans;
    }
};