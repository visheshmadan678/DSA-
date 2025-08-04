class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, n = fruits.size();
        int right = 0;
        unordered_map<int,int>mp;
        int ans = INT_MIN;
        while(right<n){
            mp[fruits[right]]++; // include that element into our map
            while(left < n && mp.size()>2){
                int ele = fruits[left];
                mp[ele]--;
                if(mp[ele]==0)mp.erase(ele); // delete that element
                left++; // increase the left pointer 
            }
            ans = max(right-left+1,ans);
            right++;
        }
        return ans;
    }
};