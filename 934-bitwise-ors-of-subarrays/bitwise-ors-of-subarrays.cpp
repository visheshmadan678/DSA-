class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        //from the next time observe the pattern carefully 
        //to solve the problem else you will not be able to solve the problem 
        // code not by vishu badmos 
        unordered_set<int>prev;
        unordered_set<int>curr;
        unordered_set<int>ans;

        for(int i=0;i<arr.size();i++){
            for(int x:prev){
                curr.insert(x|arr[i]);
                ans.insert(x|arr[i]);
            }
            curr.insert(arr[i]); // insert the element itself;
            ans.insert(arr[i]); // insert the element in the result itself 
            prev = curr;
            curr.clear(); // clear the current after using it 
        }

        return ans.size(); // return ans as size of the array 
    }
};