class Solution {
public:
    long long splitArray(vector<int>& nums) {
        //i have to generate the prime numbers from 1 to n -1
        long long n = nums.size();
        vector<bool>primes(nums.size(),true);
        primes[0] = primes[1] = false; // making them as prime

        for(int p = 2; p*p <= n; p++){
            if(primes[p]){
                for(int i= p*p; i<=n ; i+= p){
                    primes[i] = false; // marking everybody as false
                }
            }
        }
        cout<<"chcking"<<endl;
        //now iterate to check who amongst them is prime or not
        long long a = 0;
        long long b =0;
        for(int i=0;i<primes.size();i++){
            if(primes[i]){
                //it means it is true it means it's a prime number
                a += nums[i];
            }
            else{
                b += nums[i];
            }
        }
        return abs(a-b); 
    }
};