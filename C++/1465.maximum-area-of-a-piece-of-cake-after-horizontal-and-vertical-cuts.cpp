/*
 * @lc app=leetcode id=1465 lang=cpp
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
  public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int mh = horizontalCuts[0], mv = verticalCuts[0];
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            mh = max(mh, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        mh = max(mh, h - horizontalCuts.back());
        for (size_t i = 1; i < verticalCuts.size(); i++) {
            mv = max(mv, verticalCuts[i] - verticalCuts[i - 1]);
        }
        mv = max(mv, w - verticalCuts.back());
        return static_cast<int>(static_cast<long>(mh) * mv % 1000000007);
    }
};
// @lc code=end
