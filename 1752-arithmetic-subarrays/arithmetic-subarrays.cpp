class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int len = l.size(); // take the size of the ranges 
        vector<bool>ans(len);
        for(int i=0;i<len;i++){
            int left = l[i]; // these are the bounds inclusive bounds
            int right = r[i]; 
            if(right-left+1==2){
                ans[i] = true;
                continue;
            }
            vector<int>temp = nums;
            sort(temp.begin()+left,temp.begin()+(right+1)); // this will sort that part of the array 
            int diff = -1;
            bool flag  = true;
            for(int k = left;k<right;k++){
                if(diff==-1){
                    diff = temp[k+1]-temp[k];
                }
                if(temp[k+1]-temp[k]!=diff){
                    ans[i] = false;
                    flag = false;
                    break;
                }
            }
            if(flag)ans[i] = true;
        }

        return ans;
    }
};