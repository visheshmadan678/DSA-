class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); 
        priority_queue<int, vector<int>, greater<int>> freeRooms;

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busyRooms;

        vector<int> used(n, 0);
        for (int i = 0; i < n; i++) {
            freeRooms.push(i);
        }

        for (auto &meet : meetings) {
            long long start = meet[0];
            long long end = meet[1];
            long long duration = end - start;
            //this loop is to push the empty room at current time 
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                int room = busyRooms.top().second;
                busyRooms.pop();
                freeRooms.push(room);
            }
            //when empty rooms are present alot them to the current meeting
            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                used[room]++;
                busyRooms.push({end, room});
            } 
            else {
                //if they are not present alot them to the earliest end time meeting
                //but remember to update the time this time by duration + curr_end 
                auto [prevEnd, room] = busyRooms.top();
                busyRooms.pop();
                used[room]++;
                busyRooms.push({prevEnd + duration, room});
            }
        }
        //in the last find the answer for this question
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (used[i] > used[ans]) {
                ans = i;
            }
        }

        return ans;
    }
};
