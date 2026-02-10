class ExamTracker {
private:
    vector<pair<int, long long>> arr;
    long long function(vector<pair<int, long long>>& arr, int time) {
        long long total= 0;

        int left = 0, right = arr.size() - 1;
        int idx = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid].first <= time) {
                idx = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (idx != -1)
            total = arr[idx].second;

        return total;
    }

    public:
    ExamTracker() {}

    void record(int time, int score) {
        long long ans = score;
        if (!arr.empty()) {
            ans += arr.back().second;
        }
        arr.push_back({time, ans});
    }

    long long totalScore(int start, int end) {
        long long left = function(arr, start - 1);
        long long right = function(arr, end);

        return right - left;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */