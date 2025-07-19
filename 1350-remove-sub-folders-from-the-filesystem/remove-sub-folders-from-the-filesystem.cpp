class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        //code by vishu badmos
        sort(folder.begin(),folder.end());
        vector<string>ans;
        ans.push_back(folder[0]);

        for(int i=1;i<folder.size();i++){
            string last = ans.back();
            last.push_back('/');

            if(folder[i].compare(0,last.length(),last)!=0){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};