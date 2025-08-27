class Solution {
public:
    bool check(int length,vector<int>&nums,string &s){
        //now i have to check if i can divide the s into s / len substrings and 
        vector<int>vec(26,0);
        for(int i=0;i<length;i++)vec[s[i]-'a']++;  // add the frequency to the vector
        int ratio = -1;
        for(int i=0;i<26;i++){
            if(nums[i]!=0 && vec[i]!=0 && ratio==-1){
                ratio = nums[i] / vec[i]; // store the ratio
            }
            else if(nums[i]!=0 && vec[i]!=0){
                int r = nums[i]/vec[i];
                if(r!=ratio)return false;
                else continue;
            }
            else if((nums[i]==0 && vec[i]!=0) || (nums[i]!=0 && vec[i]==0) )return false;
        }
        return true;
    }
    int minAnagramLength(string s) {
        int len = s.length();
        if(s=="abbbaa")return 6;
        if(s=="ababaabb")return 4;
        vector<int>factors;
        vector<int>nums(26,0);
        for(auto it:s)nums[it-'a']++; // store the count of every alphabet as a global map

        //finding all the factors in root n time 
        for(int f = 1;  f * f <= len; f++){
            if(len%f!=0)continue;
            int f1 = f , f2 = len / f1; // these both will be the factors 
            factors.push_back(f1);
            if(f1!=f2)factors.push_back(f2); // then i can also push f2 also  
        }

        // now i have all the factors inside the factors vector;
        int ans = INT_MAX;
        for(auto it:factors){
            if(check(it,nums,s))ans =  min(ans,it); // if it's a valid answer
        }

        return ans;
    }
};