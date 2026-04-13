class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    
        int left = 0, right = 0;
        int ans = 0;
        unordered_map<char,int>mp; // use a map to solve this 

        while(right < s.length()){
            mp[s[right]]++;
            if(mp[s[right]] > 1){
                //then reduce the window upto the valid length 
                while(mp[s[right]] != 1){
                    char ch = s[left];
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch); // remove the elemetn from the map
                    }
                    left++;
                }
            }


            ans = max(ans,right-left+1);
            right++;
        }


        return ans;
    }
};