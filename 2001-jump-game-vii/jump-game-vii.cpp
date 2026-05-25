class Solution {
public:
    bool canReach(string s, int mini, int maxi) {
        queue<int>qt; int size = s.length(); 

        vector<int>visited(size,0);

        qt.push(0);
        visited[0] = 1; // mark it as visited
        int prev_max = INT_MIN;

        while(!qt.empty()){
            int idx = qt.front();
            qt.pop();

            if(idx == size - 1)return true;

            // if(visited[idx] == 1)continue; // then skip this one
            for(int k = max(prev_max,idx + mini); k <= min(size - 1, idx + maxi); k++){

                prev_max = max(k,prev_max);
                if(!visited[k] && s[k] == '0'){
                    visited[k] = 1;
                    qt.push(k);
                }
                
            }
        }

        return false;
    }
};