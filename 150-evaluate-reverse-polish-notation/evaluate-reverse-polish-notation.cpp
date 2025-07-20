class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<string>st;
        //when ever we will hit a token we will evaluate it 
        for(int i=0;i<t.size();i++){
            string s = t[i]; // can be a number or can be an operator 
            if(s=="+" || s=="-" || s=="/" || s=="*"){
                int b = stoi(st.top());
                st.pop();
                int a = stoi(st.top());
                st.pop();
                if(s=="+")st.push(to_string(a+b));
                else if(s=="-")st.push(to_string(a-b));
                else if(s=="/")st.push(to_string(a/b));
                else if(s=="*")st.push(to_string(a*b));
            }
            else{
                st.push(s);
            }
        }
        return stoi(st.top());
    }
};