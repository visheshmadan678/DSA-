class Solution {
public:
    int countCollisions(string directions) {
        stack<char>st;
        int ans = 0;
        for(auto &it:directions){
            if(!st.empty() && it == 'L' && st.top() == 'R'){
                ans += 2; // increase the answer by 2
                // and insert a stationary object inside the stackk
                st.pop();
                while(!st.empty() && st.top() == 'R'){
                    ans += 1; // these are those vehicles which are going to collide with my stationary object 
                    st.pop();
                }
                st.push('#'); // i will take hash as the stationary object 
            }
            else if(!st.empty() && it  == 'L' && st.top() == '#'){
                ans += 1;
            }
            else if(it == 'S'){
                while(!st.empty() && st.top()=='R'){
                    ans += 1;
                    st.pop();
                }
                st.push('#');
            }
            else{
                st.push(it);
            }

        }
        return ans;
    }
};