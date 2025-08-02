class Solution {
public:
    vector<string>ans;
    void recursion(int idx, int dots, string &s,string str){
        if(idx>s.length()){
            return;
        }
        if(dots==0){
            string temp = "";
            if(s[idx]=='0' && s.length()-idx!=1){
                return;
            }
            while(idx<s.length()){
                temp += s[idx];
                idx++;
            }
            if(temp.length()==0 || temp.length()>3){
                return;
            }
            if(stoi(temp)>255){
                return;
            }
            str += temp;
            ans.push_back(str);
            return;
        }

        string temp = "";
        for(int i=0;i<3 && idx+i<s.length();i++){
            temp += s[idx+i];
            str += s[idx+i];
            if(temp=="0"){
                recursion(idx+i+1,dots-1, s, str + '.');
                break;
            } else{
                if(temp.length()>0 && stoi(temp)>255) break;
                recursion(idx+i+1, dots-1, s, str + '.');
            }
            
        }
        

    }
    vector<string> restoreIpAddresses(string s) {
        string str = "";
        recursion(0,3,s,str);
        return ans;
    }
};