class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int>vec = {0,1,2,3};
        // 0 : N
        // 1 : E
        // 2 : S
        // 3 : W
        int dir = 0;
        int ans = INT_MIN;
        set<pair<int,int>> st;
        for(auto &it:obstacles){
            st.insert({it[0], it[1]});
        }
        int x  = 0; int y = 0;

        for(int i=0;i<commands.size();i++){
            int dist = commands[i];
            if(dist == -1){
                dir += 1;
                if(dir == 4){
                    dir = 0; 
                }
            }
            else if(dist == -2){
                dir -=1;
                if(dir == -1){
                    dir = 3;
                }
            }
            else{
                if(dir == 0){
                    while(dist){
                        if(st.find({x, y+1}) != st.end()){
                            break;
                        }
                        y += 1;
                        dist--;
                    }
                    int val = x*x + y*y;
                    ans = max(val,ans);
                }
                else if(dir == 1){
                    while(dist){
                        if(st.find({x+1, y}) != st.end()){
                            break;
                        }
                        x += 1;
                        dist--;
                    }
                    int val = x*x + y*y;
                    ans = max(val,ans);
                }
                else if(dir == 2){
                    while(dist){
                        if(st.find({x, y-1}) != st.end()){
                            break;
                        }
                        y -= 1;
                        dist--;
                    }
                    int val = x*x + y*y;
                    ans = max(val,ans);
                }
                else{
                    while(dist){
                        if(st.find({x-1, y}) != st.end()){ 
                            break;
                        }
                        x -= 1;
                        dist--;
                    }
                    int val = x*x + y*y;
                    ans = max(val,ans);
                }
            }
        }

        cout<<x<<" "<<y<<endl;
        return ans;
    }
};