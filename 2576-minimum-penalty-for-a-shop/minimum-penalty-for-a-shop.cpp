class Solution {
public:
    //code by vishu badmos 
    //badmashi nhi mitar
    int bestClosingTime(string customers) {
        int size = customers.size(); // represents the size of our array
        vector<long long>prefix(size+1); //will make this array on the basis of 
        vector<long long>suffix(size);

        if(customers[0] == 'N'){
            prefix[0] = 1;
        }
        else prefix[0] = 0; 
        
        for(int i=1;i<size+1;i++){
            if(customers[i] == 'N'){
                prefix[i] = 1 + prefix[i-1];
            }
            else prefix[i] = prefix[i-1]; // remain as it is
        }

        if(customers[size-1] == 'Y'){
            suffix[size-1] = 1;
        }
        else suffix[size-1] = 0;

        for(int i=size-2;i>=0;i--){
            if(customers[i] == 'Y'){
                suffix[i] = 1 + suffix[i+1];
            }
            else suffix[i] = suffix[i+1];
        }


        long long ans = 0; // i will store the index 
        long long penalty = INT_MAX; //it will hold the value of penalty

        for(int i=0;i<size+1;i++){
            long long curr = 0;
            if(i-1>=0){
                curr += prefix[i-1]; // number of times when the shop was open and no one came
            }

            if(i < size){
                curr += suffix[i]; // number of times when the shop was closed and everybody came 
            }

            if(curr < penalty){
                penalty = curr;
                ans = i; // representing the ith hour 
            }
        }
        
        return ans;
    }
};