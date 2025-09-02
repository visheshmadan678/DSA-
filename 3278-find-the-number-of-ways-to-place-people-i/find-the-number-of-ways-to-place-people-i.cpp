class Solution {
public:
    bool upper_left(pair<int, int> p1, pair<int, int> p2) {
        // i have both the points simply check them if they can form the
        // rectangle y coordinate should be greater for point1 as compared to point 2 
        int y1 = p1.second; int y2 = p2.second; 
        int x1 = p1.first; int x2 = p2.first;
        return y1 >= y2 && x1 <= x2; 
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int count = 0;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i != j) {
                    pair<int, int> p1 = {points[i][0], points[i][1]};
                    pair<int, int> p2 = {points[j][0], points[j][1]};
                    int x1 = min(p1.first,p2.first); int x2 = max(p1.first,p2.first);
                    int y1 = min(p1.second,p2.second);  int y2 = max(p1.second,p1.second);
                    // first i need to check the first condition that upper left
                    if (upper_left(p1, p2)) {
                        //now if both are healthy for forming a rectangle check for other points also 
                        cout<<p1.first<<p1.second<<p2.first<<p2.second<<endl;
                        bool flag = true;
                        for(int k=0;k<n;k++){
                            // yeh vo saare points hai vo beech mein lie kr skte hai inke 
                            if(k!=i && k!=j){
                                pair<int,int>p3 = {points[k][0],points[k][1]};
                                if((p3.first>=x1 && p3.first<=x2) && (p3.second>=y1 && p3.second<=y2)){
                                    flag = false;
                                    break;
                                }
                            }
                        }
                        if(flag)count++;
                    }
                }
            }
        }

        return count;
    }
};