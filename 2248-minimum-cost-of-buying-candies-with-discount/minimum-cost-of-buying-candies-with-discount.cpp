class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0;
        priority_queue<int,vector<int>>qt;

        for(auto &it:cost){
            qt.push(it);
        }

        while(!qt.empty()){
            int ele1 = qt.top();
            qt.pop();

            int ele2 = 0;
            if(!qt.empty()){
                ele2 = qt.top();
                qt.pop();
            }

            int ele3 = 0;
            if(!qt.empty()){
                ele3 = qt.top();
                qt.pop();
            }

            ans += (ele1 + ele2);
        }

        return ans;
    }
};