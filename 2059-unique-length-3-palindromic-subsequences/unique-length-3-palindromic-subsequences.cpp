class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<int>st;
        vector<int>nums(26,0);
        int size = s.length();

        vector<vector<int>>prefix(size); // i will take these arrays to maintain that charcters 
        vector<vector<int>>suffix(size); // same for this one also 

        for(int i=0;i<size;i++){
            nums[s[i]-'a']++; // increase the value of that 
            prefix[i] = nums; // change value of every value of prefix
        }
        
        vector<int>temp(26,0);

        for(int i=size-1;i>=0;i--){
            temp[s[i]-'a']++;
            suffix[i] = temp;
        }
        

        for(int i=1;i<=size-2;i++){
            //now i have to count for every string
            for(int j=0;j<26;j++){
                if(prefix[i-1][j]!=0 && suffix[i+1][j]!=0){
                    //it means we got a palidrome
                    st.insert(26 * j + (s[i]-'a'));
                }
            }
        }

        return st.size();
    }
};