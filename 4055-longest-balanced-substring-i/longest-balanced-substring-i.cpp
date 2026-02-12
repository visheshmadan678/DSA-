class Solution {
public:
    int longestBalanced(string s) {
        //doing brute force on this will solve it tommorrow perfectly the second part for this
        int ans = 1; 
        for(int i=0;i<s.length();i++){
            int a = 0, b = 0, c = 0;
            vector<int>nums(26,0);
            for(int j=i;j<s.length();j++){
                nums[s[j]-'a']++; int temp = -1; bool flag = true;
                for(int k=0;k<26;k++){
                    if(nums[k]!=0 && temp == -1){
                        temp = nums[k];
                        continue;
                    }
                    if(temp != nums[k] && nums[k]!=0){
                        flag = false;
                        break;
                    }
                }
                if(temp != -1 && flag){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};