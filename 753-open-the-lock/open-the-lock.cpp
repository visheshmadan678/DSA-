class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> qt;

        string start = "0000";
        if (deads.count(start)) return -1; // cannot even start
        if (start == target) return 0;     // already unlocked

        qt.push(start);
        visited.insert(start);

        int time = 0;
        while (!qt.empty()) {
            int sz = qt.size();
            while (sz--) {
                string ele = qt.front();
                qt.pop();

                if (ele == target) return time;

                // generate neighbors (turn one wheel up or down)
                for (int i = 0; i < 4; i++) {
                    char ch = ele[i];

                    // wheel up
                    string up = ele;
                    up[i] = (ch == '9' ? '0' : ch + 1);

                    // wheel down
                    string down = ele;
                    down[i] = (ch == '0' ? '9' : ch - 1);

                    if (!deads.count(up) && !visited.count(up)) {
                        visited.insert(up);
                        qt.push(up);
                    }
                    if (!deads.count(down) && !visited.count(down)) {
                        visited.insert(down);
                        qt.push(down);
                    }
                }
            }
            time++;
        }
        return -1;
    }
};
