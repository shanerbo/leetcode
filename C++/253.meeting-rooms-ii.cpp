/*
 * @lc app=leetcode id=253 lang=cpp
 *
 * [253] meeting rooms
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
  public:
    bool canAttendMeetings(vector<vector<int>> &in) {
        if (in.empty()) {
            return true;
        }

        sort(in.begin(), in.end());
        for (size_t i = 0; i < in.size() - 1; ++i) {
            if (in[i][1] > in[i + 1][0]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
