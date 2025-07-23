class Solution {
public:
    int func(char t, char cmp, string &s, int val){
        int ans = 0;
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && st.top()==t && s[i]==cmp){
                st.pop();
                ans += val;
            }
            else{
                st.push(s[i]);
            }
        }
        s = "";
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        int ans = 0;

        if(x>y){
            //if x is greater than y 
            ans += func('a','b',s,x);
            ans += func('b','a',s,y);
        }
        else{
            //if they are equal or y is greater than x 
            ans += func('b','a',s,y);
            ans += func('a','b',s,x);
        }

        return ans;
    }
};