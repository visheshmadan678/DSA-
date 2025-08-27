class Solution {
public:

    bool check(int x){
        if(x < 2) return false;   
        for(int f = 2; f * f <= x; f++){
            if(x % f == 0) return false;
        }
        return true;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++){
            if(check(nums[i])) nums[i] = -1;
        }

        int maxi = INT_MIN;
        int mini = INT_MAX;

    
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == -1){
                maxi = max(i, maxi);
                mini = min(i, mini);
            }
        }

        if(maxi == INT_MIN) return 0;

        return maxi - mini;
    }
};
