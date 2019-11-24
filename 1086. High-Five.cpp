/*
 * @lc app=leetcode id=1086 lang=cpp
 *
 *
 */

class Solution {
  public:
    vector<vector<int>> highFive(vector<vector<int>> &items) {
        vector<vector<int>> res;
        if (items.empty()) {
            return {{}};
        }
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map;
        for (auto const &item : items) {
            if (map[item[0]].size() >= 5 && map[item[0]].top() < item[1]) {
                map[item[0]].pop();
                map[item[0]].push(item[1]);
            } else if (map[item[0]].size() < 5) {
                map[item[0]].push(item[1]);
            }
        }
        for (auto const item : map) {
            int sum = 0;
            auto queue = item.second;
            auto size = queue.size();
            for (int i = 0; i < size; ++i) {
                sum += queue.top();
                queue.pop();
            }
            res.push_back({item.first, sum / size});
        }
        auto cmp = [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        };
        sort(res.begin(), res.end(), cmp);
        return res;
    }
};