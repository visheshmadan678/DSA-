class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int,int>mp;
        int sum = 0;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i]; // store the sum
            mp[nums[i]] = i;
        } // add the element into the map
        
        int ans = INT_MIN;

        for(int i=0;i<nums.size();i++){
            int ele = nums[i]; // element to check for inside the array 
            int exp = 2*ele;
            int to_find = sum - (2*ele);
            if(mp.find(to_find)!=mp.end() ){
                //if the element is found inside the map
                if(mp[to_find]!=i)ans = max(ans,to_find);
            }
        }

        cout<<sum<<" ";

        return ans;
    }
};