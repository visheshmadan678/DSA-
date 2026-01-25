class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        long long size = nums.size(); sort(nums.begin(),nums.end());
        if(size == 1)return 0;
        vector<long long>diff;
        for(int i=0;i<size-k+1;i++){
            long long difference = nums[i+k-1] - nums[i];
            diff.push_back(difference);
        }
        int ans = *min_element(diff.begin(),diff.end());
        return ans;
    }
};