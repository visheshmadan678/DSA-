class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n%2==0){
            for(int i=n/2;i>=1;i--){
                ans.push_back(i);
                ans.push_back(-i);
            }
        }
        else{
            //when n is odd
            n--;
            ans.push_back(0);
            for(int i=n/2;i>=1;i--){
                ans.push_back(i);
                ans.push_back(-i);
            } 
        }
        return ans;
    }
};