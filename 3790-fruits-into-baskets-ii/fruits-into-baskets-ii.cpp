class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& basket) {
        //i will just run a brute force i will find the optimal basket for every fruit 
        //code by vishu badmos
        int cnt = 0;
        for(int i=0;i<fruits.size();i++){
            bool flag = false;
            for(int j=0;j<basket.size();j++){
                if(basket[j]!=-1 && basket[j]>=fruits[i]){
                    flag = true;
                    basket[j] = -1; 
                    break;
                }
            }
            if(flag==false){
                cnt++;
            }
        }
        return cnt;
    }
};