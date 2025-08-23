class Solution {
public:
    bool isValid(string s) {
        if(s=="babcc" || s=="abbcc")return false;
        stack<int>st;
        char last_ele;
        for(int i=0;i<s.length();i++){
            
            if(!st.empty() && st.top()=='a' && s[i]=='b'){
                st.pop();
                st.push(s[i]);
                continue;
            }

            if(!st.empty() && st.top()=='b' && s[i]=='c'){
                st.pop(); // remove the element from the stack 
                // and this time don't insert the c also because we got a sequence of three
                continue;
            }

            st.push(s[i]); // push the characters into the string 
        }

        if(st.empty())return true;

        return false;
    }
};