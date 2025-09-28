class Solution {
public:
    //code by vishu badmos
    bool check_triangle(int a, int b, int c){
        return (a + b > c) && (b + c > a) && (a + c > b);
    }
    int largestPerimeter(vector<int>& nums) {
        //sort krke piche se triplet uthane start kro 
        sort(nums.begin(),nums.end());
        int i = nums.size()-1;
        while(i>=2){
            int k = i;
            if(k>=2){
                int x = nums[k]; int y = nums[k-1]; int z = nums[k-2];
                bool flag = check_triangle(x,y,z);
                if(flag){
                    return x+y+z;
                }
            }
            i--;
        }
        return 0;
    }
};