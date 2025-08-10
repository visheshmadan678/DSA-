class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if(n==1)return true;
        int i = 1;
	    set<string>st;
        for (int i = 1; i <= 31; i++) {
            string str = to_string(1LL << i); 
            sort(str.begin(),str.end());
            st.insert(str);
        }

	    string str2 = to_string(n);
        sort(str2.begin(),str2.end()); 
	    
        return st.count(str2);
    }
};