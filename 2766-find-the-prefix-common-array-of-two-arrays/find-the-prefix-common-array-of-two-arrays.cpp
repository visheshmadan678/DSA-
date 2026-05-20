class Solution {
public:
    //code by vishu badmos
    //badmashi nahi mitar
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans(A.size()); // our answer vector 
        unordered_set<int>st1; unordered_set<int>st2;
        int size = A.size();

        for(int i = 0; i < size; i++){
            int ele1 = A[i]; int ele2 = B[i]; 

            if(ele1 == ele2){
                ans[i]++; 
                continue;
                // and continue the loop because we cannot take the double counting
            }
            st1.insert(ele1); st2.insert(ele2); // insert both the elements into the set

            //now a asks b about ele1 
            if(st2.count(ele1)){
                ans[i]++;
            }

            //and b asks a about ele2
            if(st1.count(ele2)){
                ans[i]++;
            }
        } 

        //now in the end take the prefix sum of ans 

        for(int i = 1; i < size; i++){
            ans[i] = ans[i-1] + ans[i];
        }

        return ans;
    }
};