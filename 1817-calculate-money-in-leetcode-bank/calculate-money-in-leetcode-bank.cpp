class Solution {
public:
    int totalMoney(int n) {
        if(n <= 7){
            //it means i have to return 
            return n * (n+1) / 2;  // sum of first n natural numbers as my answer 
        }
        int ans = 0;
        //now comes the cases in which n is greater than 7 or something 
        int divisor = n / 7;
        int remainder = n % 7; 

        ans += (divisor * (2 * 28 + (divisor - 1)* 7));
        ans /= 2; // some of n terms of an arithmetic progression
        cout<<ans<<endl;
        if(remainder){
            //if remainder is left somehow and it's not equal to the zero value 
            int a = divisor + 1; // this is the starting value of that week which is going on 
            int temp = remainder * ((2 * a) + (remainder - 1) * 1);
            temp /= 2;
            ans += temp;
        }
        return ans;
    }
};