class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        //not solved by me i saw a youtube video 
        unordered_map<long long,long long>mp;
        long long mini = LLONG_MAX;
        for(long long it:basket1){mp[it]++;mini = min(mini,it);}
        for(long long it:basket2){mp[it]--;mini = min(mini,it);} // now the map contains the extra elements

        vector<long long>nums;

        for(auto it:mp){
            if(it.second==0)continue;
            if(it.second%2!=0)return -1;
            for(int i=1;i<=abs(it.second/2);i++){
                nums.push_back(it.first); // pushing the element freq / 2 times 
            }

        }

        long long cost = 0;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()/2;i++){
            cost += min(nums[i],mini*2);
        }

        return cost;
    }
};