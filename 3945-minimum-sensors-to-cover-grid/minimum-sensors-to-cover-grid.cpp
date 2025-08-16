class Solution {
public:
    //code by vishu badmos 
    int minSensors(int n, int m, int k) {
        int x = 2*(k+1)-1; // new grid value
        int qt1 = n/x;
        int qt2 = m/x;
        int rem1 = n%x;
        int rem2 = m%x;
        if(qt1==0){
            qt1 = 1;
        }
        else{
            if(rem1)qt1++;
        }
        
        if(qt2==0){
            qt2 = 1;
        }
        else{
            if(rem2)qt2++;
        }
        
        return qt1 * qt2; // return the product of both of them
    }
};