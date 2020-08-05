/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
  public:
    vector<Interval *> employeeFreeTime(vector<vector<Interval *>> schedule) {
        auto cmp = [](Interval *a, Interval *b) { return a->start > b->start; };
        priority_queue<Interval *, vector<Interval *>, decltype(cmp)> schedules(cmp);
        for (auto interval : schedule) {
            for (auto s : interval) {
                schedules.push(s);
            }
        }
        int j = 0;
        vector<Interval *> res;
        int maxEnd = schedules.top()->end;
        while (schedules.size() > 0) {
            int start = schedules.top()->start;
            if (start <= maxEnd) {
                maxEnd = max(schedules.top()->end, maxEnd);
            } else {
                Interval *interval = new Interval(maxEnd, start);
                res.push_back(interval);
                maxEnd = schedules.top()->end;
            }
            schedules.pop();
        }
        return res;
    }
};