class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;

        for(auto it:moves){
            if(it=='U'){
                y+=1;
            }
            else if(it=='D'){
                y-=1;
            }
            else if(it=='L'){
                x-=1;
            }
            else if(it=='R'){
                x+=1;
            }
        }


        return x==0 && y==0;
    }
};