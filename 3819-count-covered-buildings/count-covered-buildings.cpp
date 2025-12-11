class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int, set<int>> x_to_y, y_to_x;

        // Fill the maps with building coordinates
        for (const auto& building : buildings) {
            int x = building[0];
            int y = building[1];
            x_to_y[x].insert(y);
            y_to_x[y].insert(x);
        }

        int count = 0;

        for (const auto& building : buildings) {
            int x = building[0];
            int y = building[1];

            bool hasLeft = *x_to_y[x].begin() < y; // smallest y is less than current y
            bool hasRight = *x_to_y[x].rbegin() > y; // largest y is greater than current y

            // Check if there's any building above and below on the same column
            bool hasAbove = *y_to_x[y].begin() < x; // smallest x is less than current x
            bool hasBelow = *y_to_x[y].rbegin() > x; // largest x is greater than current x

            if (hasLeft && hasRight && hasAbove && hasBelow) {
                count++;
            }
        }

        return count;
    }
};
