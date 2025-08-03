class Solution {
public:
    vector<int>answers; 
    void recursion(int idx, vector<int>&top, int adder,int sum){
        if(idx>=top.size()){
            answers.push_back(adder+sum);
            return;
        }
        answers.push_back(adder+sum);  // taking by default answer as target itself as the greateest value
        for(int i = 0;i<3;i++){
            recursion(idx+1,top,adder,sum+top[idx]*i); // taking all the three possibilites
        }
    }
    int closestCost(vector<int>& base, vector<int>& top, int target) {
         // generating all the toppings 
        //for every number there are three possibilites 0 1 2 iterate through all of them using standard recursion
        for(int i=0;i<base.size();i++){
            //i have to check for every base guys 
            recursion(0,top,base[i],0); 
        }
        int diff = INT_MAX;
        int ans = -1;
        for(auto it:answers){
                if(abs(target-it)<diff){
                ans = it; // take that it
                diff = abs(target-it);
            }
            else if(abs(target-it)==diff){
                ans = min(ans,it); // take the minium of them
            }
        }
        return ans;
    }
};