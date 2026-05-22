class Solution {
public:
    int search(vector<int>& nums, int target) {

        if(nums.size() == 1)return nums[0] == target ? 0 : -1;
        int low = 0; int high = nums.size()-1; 

        while(low <= high){
            int mid =  (low + high) / 2;

            if(nums[mid] == target)return mid;

            if(nums[low] <= nums[mid]){
                //if left half is sorted
                if(target >= nums[low] && target < nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                //if right half if sorted
                if(target > nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }


        return -1;
    }
};