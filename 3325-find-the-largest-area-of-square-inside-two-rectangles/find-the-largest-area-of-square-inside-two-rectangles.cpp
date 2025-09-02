class Solution {
public:
    bool intersect(pair<int,int> a1, pair<int,int> a2, pair<int,int> b1, pair<int,int> b2) {
        return !(a2.first <= b1.first || b2.first <= a1.first ||
                 a2.second <= b1.second || b2.second <= a1.second);
    }

    long long largestSquareArea(vector<vector<int>>& bottomleft, vector<vector<int>>& topright) {
        int n = bottomleft.size();
        long long ans = 0;
        
        for(int i=0;i<n;i++){
            pair<int,int> x1 = {bottomleft[i][0], bottomleft[i][1]};
            pair<int,int> x2 = {topright[i][0], topright[i][1]};
            for(int j=i+1;j<n;j++){ 
                pair<int,int> y1 = {bottomleft[j][0], bottomleft[j][1]};
                pair<int,int> y2 = {topright[j][0], topright[j][1]};
                
                if(intersect(x1, x2, y1, y2)){
                    int x_left   = max(x1.first, y1.first);
                    int y_bottom = max(x1.second, y1.second);
                    int x_right  = min(x2.first, y2.first);
                    int y_top    = min(x2.second, y2.second);

                    int width  = max(0, x_right - x_left);
                    int height = max(0, y_top - y_bottom);

                    int side = min(width, height);
                    ans = max(ans, 1LL * side * side);
                }
            }
        }

        return ans;
    }
};
