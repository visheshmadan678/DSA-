class Solution {
public:
    int find(int target, int left, int right, vector<int>&nums2){
        int idx = -1;
        while(left <= right){
            int mid = (right + left) / 2;
            if(nums2[mid] >= target){
                //valid case
                idx = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return idx;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(); int size2 = nums2.size();
        int ans = INT_MIN;

        for(int i=0;i<size1;i++){
            int curr_ele = nums1[i];
            int left = i;
            int idx = find(curr_ele,left,nums2.size()-1,nums2);

            if(idx != -1){
                ans = max(ans,idx - i);
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};