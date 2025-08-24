class Solution {
public:
    //CODE BY VISHU BADMOS BADMASHI NHI MITAR 
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0;
        int count=0;
        int ans=0;
        while(j<nums.size()){
            if(nums[j]==0)count++;
            while(i<j && count>1){
                if(nums[i]==0)count--;
                i++;
            }
        ans=max(ans,j-i);
        j++;
        }
        return ans;
    }
};