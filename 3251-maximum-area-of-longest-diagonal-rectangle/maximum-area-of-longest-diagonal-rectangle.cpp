class Solution {
public:
    //code by vishu badmos 
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = INT_MIN;
        int sec = INT_MIN;
        unordered_map<int,double>mp;
        for(int i=0;i<dimensions.size();i++){
            //iterate through the array
            double breadth = dimensions[i][1]; 
            double length = dimensions[i][0], dag = (length*length) + (breadth * breadth);
            int area = length * breadth;// calculate the diagonal
            mp[area] = max(dag,mp[area]);
        }

        //iterate through the mp to calculate the maximum area of largest diagonal

        for(auto it:mp){
            double dlen = it.second;
            int area = it.first;
            if(dlen>sec){
                ans = area;  // store the area of that rectangle
                sec = dlen;
            }
            else if(dlen==sec){
                ans = max(ans,area); // else store the maximum in the ans 
            }
        }

        int fin = ans;
        return fin;
    }
};