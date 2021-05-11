/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        auto cmp = [](vector<int> a, vector<int> b) {
            return a[0] * a[0] + a[1] * a[1] > (b[0] * b[0] + b[1] * b[1]);
        };
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (const auto &p : points) {
            pq.push(p);
        }
        for (size_t i = 0; i < K; ++i) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
