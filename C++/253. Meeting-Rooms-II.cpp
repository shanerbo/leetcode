class Solution {
  public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        int ret = 1;
        if (intervals.size() < 1) {
            return 0;
        } else {
            if (intervals.size() == 1)
                return ret;
            auto cmp = [](vector<int> a, vector<int> b) {
                if (a[1] == b[1]) {
                    return a[0] >= b[0];
                }
                return a[1] <= b[1];
            };
            priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
            for (auto const &interval : intervals) {
                pq.push(interval);
            }
            vector<int> curr;
            vector<int> next;
            while (pq.size() > 1) {
                curr = pq.top();
                pq.pop();
                next = pq.top();
                cout << curr[0];
                if (next[1] > curr[0]) {
                    ret++;
                }
                curr.clear();
                next.clear();
            }

            return ret;
        }
    }
};