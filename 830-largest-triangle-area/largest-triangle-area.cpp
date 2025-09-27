class Solution {
public:
    double herons_formula(vector<int>a, vector<int>b , vector<int>c){
        double x = sqrt(pow(a[0]-b[0],2) + pow(a[1]-b[1],2));
        double y = sqrt(pow(a[0]-c[0],2) + pow(a[1]-c[1],2));
        double z = sqrt(pow(b[0]-c[0],2) + pow(b[1]-c[1],2));
        double s = (x + y + z) / 2.0;
        double area = sqrt(s * (s-x) * (s-y) * (s-z));
        return area;
    }
    
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0.0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    ans = max(ans, herons_formula(points[i], points[j], points[k]));
                }
            }
        }
        return ans;
    }
};
