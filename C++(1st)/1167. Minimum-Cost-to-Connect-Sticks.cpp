class Solution {
  public:
    int connectSticks(vector<int> &sticks) {
        auto cmp = [](int a, int b) { return a > b; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (auto const &stick : sticks) {
            pq.push(stick);
        }
        int res = 0, sum = 0;
        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            sum += first + second;
            pq.push(first + second);
        }
        return sum;
    }
};