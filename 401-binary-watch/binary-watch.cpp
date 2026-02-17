class Solution {
public:
    void recursion_hours(int idx, int sum, int curr_ele, int total_ele,
                         vector<int>& ds, int sum_max, vector<int>& hours) {

        if (idx >= hours.size()) {
            if (curr_ele == total_ele && sum <= sum_max)
                ds.push_back(sum);
            return;
        }

        // pick
        recursion_hours(idx + 1, sum + hours[idx], curr_ele + 1, total_ele, ds,
                        sum_max, hours);

        // not pick
        recursion_hours(idx + 1, sum, curr_ele, total_ele, ds, sum_max, hours);
    }
    vector<string> readBinaryWatch(int turnedOn) {
        if (turnedOn >= 9)
            return {};
        else if (turnedOn == 0)
            return {"0:00"};
        vector<int> hours = {8, 4, 2, 1};
        vector<int> minutes = {32, 16, 8, 4, 2, 1};
        vector<string> ans;

        for (int i = 0; i <= turnedOn; i++) {
            int a = i;
            int b = turnedOn - i;
            if (a >= hours.size() || b >= minutes.size())
                continue; // it means i cannot take all the elements
            vector<int> hours_valid;
            vector<int> minutes_valid;
            recursion_hours(0, 0, 0, a, hours_valid, 11, hours);
            recursion_hours(0, 0, 0, b, minutes_valid, 59, minutes);

            for (int i = 0; i < hours_valid.size(); i++) {
                string temp = "";
                temp += to_string(hours_valid[i]) + ":";
                for (int j = 0; j < minutes_valid.size(); j++) {
                    if (minutes_valid[j] == 0) {
                        temp += "00";
                    } else if (minutes_valid[j] < 10) {
                        temp += ("0" + to_string(minutes_valid[j]));
                    } else {
                        temp += to_string(minutes_valid[j]);
                    }
                    ans.push_back(temp); // first insert the answer into the
                                         // temp then delete
                    temp.pop_back();
                    temp.pop_back();
                }
            }
        }

        return ans;
    }
};