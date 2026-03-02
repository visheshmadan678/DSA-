class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> nums;
        int m = grid.size(); int n = grid[0].size();

        for(int i=0;i<m;i++){
            int zeroes = 0;
            int j = n-1;
            while(j >=0 && grid[i][j] == 0){
                zeroes++;
                j--;
            }
            nums.push_back(zeroes);
        }

        int counter = 0;
        //for every index i need a value which will satisfy that value 
        int k = m-1; int ans = 0;
        // for(auto &it:nums)cout<<it<<" ";
        cout<<endl;

        for(int i=0;i<nums.size();i++){
            int current = nums[i]; // this is my current value
            // cout<<current<<endl;
            if(current >= k){
                k--;
                continue; // the loop
            } // no need to find the next value 
            else{
                //if the current is less than expected k value then find the first greater element greater than equal
                //to our value
                int j = i + 1;
                for(;j<nums.size();j++){
                    if(nums[j] >= k){
                        break;
                    }
                }
                if(j == nums.size())return -1; // invalid case 
                int temp = nums[j]; // it has the element which i want in the current ith index 
                for(int x = j; x > i; x--){
                    nums[x] = nums[x-1];
                }

                nums[i] = temp;
                //also i have to update the array side by side 
                ans += j-i; // these are the operations which i performed
            }
            k--; // reduce the value of k
        }
        return ans;
    }
};