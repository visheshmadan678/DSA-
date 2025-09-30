class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==1)return true; // in this case i can always divide the array into k groups of distinct elements
        if(n % k != 0)return false; // it means i can never divide the array into the k groups of equal sizes
        //now the next thing is that i have to think of an approach for this problem 
        unordered_map<int,int>mp;
        for(auto &it:nums)mp[it]++; // take the input inside them map
        //we will go by inversion thinking we will find out the false cases 
        int dividend = n / k;
        for(auto &it:mp){
            int freq = it.second;
            if(freq > dividend)return false;
        }
        return true;
    }
};