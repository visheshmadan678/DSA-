class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int size = nums.size();
        vector<int>answer(size); map<int,pair<int,int>>mp;
        long long sum = 0;

        for(int i = 0; i < size; i++){
            sum += nums[i];
            mp[i].first = sum;
        }

        sum = 0; // initialize sum again to zero

        for(int i = size - 1; i >= 0; i--){
            sum += nums[i];
            mp[i].second = sum;
        }

        for(int i = 0; i < size; i++){
            answer[i] = abs(mp[i].first - mp[i].second);
        }

        return answer;
    }
};