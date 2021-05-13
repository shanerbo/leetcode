/*
 * @lc app=leetcode id=253 lang=cpp
 *
 * [253] meeting rooms
 */

// @lc code=start
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
class Solution {
  public:
    int minMeetingRooms(vector<vector<int>> &ins) {
        if (ins.empty()) {
            return 0;
        }
        sort(ins.begin(), ins.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &i : ins) {
            if (!pq.empty() and pq.top() <= i[0]) {
                pq.pop();
            }
            pq.push(i[1]);
        }
        return pq.size();
    }
};
// @lc code=end
