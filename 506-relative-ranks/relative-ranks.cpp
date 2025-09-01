class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        priority_queue<pair<int,int>>qt; 
        vector<string>ans(score.size());
        for(int i=0;i<score.size();i++){
            int ele = score[i];
            int idx  = i;
            qt.push({ele,idx}); // pushed into the queue
        }


        int counter = 0;

        while(!qt.empty()){
            pair<int,int>p = qt.top();
            qt.pop(); 
            int idx = p.second;
            int element = p.first;
            // ab humko is p par operation krna hai bus
            if(counter>=0 && counter<=2){
                if(counter==0){
                    ans[idx] = "Gold Medal";
                }
                else if(counter==1){
                    ans[idx] = "Silver Medal";
                }
                else{
                    ans[idx] = "Bronze Medal";
                }
            }else{
                //ab hamara pehle teen khtml ho chuke hai 
                ans[idx] = to_string(counter+1);
                
            }
            counter++;
        }

        return ans;
    }
};