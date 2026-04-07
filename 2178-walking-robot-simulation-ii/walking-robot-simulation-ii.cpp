class Robot {
public:
    vector<vector<int>>nums;
    string dir = "East";
    // vector<int>direction = {0,1,2,3};
    int x = 0; int y = 0; // representing the origin
    Robot(int width, int height) {
        //this will make a grid for the robot so that it can travel
        vector<vector<int>>vec(height,vector<int>(width));
        this->nums = vec;
    }
    
    void step(int num) {
        //this function will edit the positions globally and return them and also simulate them in order
        //this function will also edit the direction at each and every step 
        int perimeter = (2 * (nums[0].size() + nums.size())) - 4;
        num %= perimeter;

        if(num == 0)num = perimeter;
        while(num){
            if(dir == "East"){
                //when the direction is east
                    //take the case for the out of bounds 
                    if(x + num >= nums[0].size()){
                        //then change the direction 
                        num -= (nums[0].size() - x - 1);
                        x = nums[0].size() - 1;
                        dir = "North";
                        // y++;
                    }
                    else{
                        x += num;
                        num = 0;
                    }
            }
            else if(dir ==  "West"){
                //when the direction is west
                if(x - num < 0){
                        //then change the direction 
                        num -= x;
                        x = 0;
                        dir = "South";
                        // y--;
                    }
                    else{
                        x -= num;
                        num = 0;
                    }
            }
            else if(dir == "North"){
                //when the direction is north
                if(y + num >= nums.size()){
                        //then change the direction 
                        num -= (nums.size() - y - 1);
                        y = nums.size() - 1;
                        dir = "West";
                        // x--;
                    }
                    else{
                        y += num;
                        num = 0;
                    }
            }
            else{
                //when the direction is "south"
                    if(y - num < 0){
                        //then change the direction 
                        num -= y;
                        y = 0;
                        dir = "East";
                        // x++;
                    }
                    else{
                        y -= num;
                        num = 0;
                    }
            }
        }
    }

    vector<int>getPos(){
        return {x,y};
    }

    string getDir(){
        return dir;
    }
};