class Solution {
public:
    int maxDistance(vector<int>& colors) {
        //first number from the back which is not equal to my current number
        //so store the last occurence for every different type of color and if 
        // last occurence is at the last then return n - 2 as the answer else return n - 1 as the answer
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<colors.size();i++){
            int color = colors[i];
            mp[color].push_back(i);
        }

        int ans = INT_MIN;

        for(auto &it:mp){
            int current_color = it.first;
            vector<int>indices = it.second; int size = indices.size(); int last = colors.size() - 1;
            int last_index = indices[size-1]; int first = indices[0];

            if(last_index != last){
                ans = max(ans,last - first); // this can be my answer directly
            } 
            else{
                //if the last index is equal to last it means that element is present in the last also 
                for(int i=size-1;i>=1;i--){
                    int curr = indices[i-1]; int next = indices[i];
                    if(abs(curr - next) != 1){
                        //it means i have my answer here itself
                        ans = max(ans,next-1);
                    } 
                } 
            }
        }

        return ans;
    }
};