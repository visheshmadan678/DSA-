class Solution {
public:
    bool is_vowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int maxFreqSum(string s) {
        int vmax = INT_MIN;
        int cmax = INT_MIN;
        int cnt1 = 0,cnt2 = 0;
        unordered_map<int,int>mp;
        for(auto it:s)mp[it]++; // insert the elements into the map 
        for(auto it:mp){
            if(is_vowel(it.first)){
                vmax = max(vmax,it.second);
                cnt1++;
            }
            else{
                cmax = max(cmax,it.second);
                cnt2++;
            }
        }
        if(cnt1 == 0)vmax = 0;
        if(cnt2 == 0)cmax = 0;
        return vmax + cmax;
    }
};