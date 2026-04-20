class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = INT_MIN;

        for(int i=0;i < colors.size();i++){
            int curr = colors[i];
            for(int j = i+1; j < colors.size();j++){
                int curr2 = colors[j];
                if(curr != curr2){
                    ans = max(ans,j - i);
                }
            }
        }

        return ans;
    }
};