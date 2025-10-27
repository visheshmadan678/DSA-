class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        if(bank.size() == 1){
            return 0;
        }
        int ans = 0;
        vector<int>devices;
        for(auto &it:bank){
            int cnt = 0;
            for(auto &j:it){
                if(j=='1'){
                    cnt++;
                }
            }
            if(cnt!=0)devices.push_back(cnt);
        }
        
        if(devices.size() > 1){
            for(int i=0;i<devices.size()-1;i++){
                ans += (devices[i] * devices[i+1]);
            }
        }
        
        return ans;
    }
};