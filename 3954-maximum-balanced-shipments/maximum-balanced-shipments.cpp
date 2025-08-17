class Solution {
public:
    int maxBalancedShipments(vector<int>& nums) {
        int count = 0, i = 0;
        int n = nums.size();
        int maxi = -1;
        while(i<n){
            maxi = nums[i]; // assign the first element as the maximum
            i++;
            while(i<n && nums[i]>=maxi){
                //the moment i will get the smaller element than maxi i will stop 
                maxi = max(nums[i],maxi); // also update the maxi also 
                i++;
            }
            if(i<n && nums[i]<maxi){
                //if our current index is that index which is smaller than our i than store the answer
                count +=1; // increase the count 
            }
            i++;
        }

        return count;
    }
};