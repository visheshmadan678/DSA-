class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        //note that its the inclusive range 
        int n = nums.size();
        if(n<=3)return false; // cannot form a trionic array 

        for(int i=1;i<=n-3;i++){
            //this is the range where i can place my p variable 
            for(int j=i+1;j<=n-2;j++){
                //this the range where i can place my q 
                //now check if this range is valid or not
                bool f1 = false,f2 = false, f3 = false;
                for(int k=0;k<i;k++){
                    if(nums[k]<nums[k+1])f1 = true;
                    else{
                        f1 = false;
                        break;
                    }
                }
                if(f1 == false)continue;
                
                for(int k=i;k<j;k++){
                    if(nums[k]>nums[k+1])f2 = true;
                    else{
                        f2 = false;
                        break;
                    }
                }
                if(f2 == false)continue;
                for(int k=j;k<n-1;k++){
                    if(nums[k]<nums[k+1])f3 = true;
                    else {
                        f3 = false;
                        break;
                    }                  
                }
                if(f3 == false)continue;
                //through out all the loops if the flag becomes true i will return true
                if(f1 && f2 && f3)return true;
            }
        }

        return false;
    }
};