class Solution {
public:
    bool solve(int idx, vector<int>&arr, vector<int>&visited){

        if(arr[idx] == 0){
            //if we reached the zero succesfully return true;
            return true;
        }
        if(visited[idx] == 1){
            //if its already visited 
            return false;
        }
        visited[idx] = 1; // mark the index as visited 

        int val = arr[idx];

        bool flag = false;
        //either i can go left 
        if(idx - val >= 0){
            flag = solve(idx - val, arr, visited);
            if(flag)return flag;
        }

        //either i can go right
        if(idx + val < arr.size()){
            flag = solve(idx + val, arr, visited);
            if(flag)return flag;
        }

        return flag;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>visited(arr.size(),0);
        return solve(start,arr,visited);
    }
};