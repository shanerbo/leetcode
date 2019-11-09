/*
 * @lc app=leetcode id=939 lang=cpp
 *
 * [939] Minimum Area Rectangle
 *
 * https://leetcode.com/problems/minimum-area-rectangle/description/
 *
 * algorithms
 * Medium (51.56%)
 * Likes:    396
 * Dislikes: 73
 * Total Accepted:    29K
 * Total Submissions: 56.2K
 * Testcase Example:  '[[1,1],[1,3],[3,1],[3,3],[2,2]]'
 *
 * Given a set of points in the xy-plane, determine the minimum area of a
 * rectangle formed from these points, with sides parallel to the x and y
 * axes.
 * 
 * If there isn't any rectangle, return 0.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
 * Output: 4
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
 * Output: 2
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= points.length <= 500
 * 0 <= points[i][0] <= 40000
 * 0 <= points[i][1] <= 40000
 * All points are distinct.
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    int minAreaRect(vector<vector<int>> &points) {
        if (points.empty()) {
            return 0;
        }
        unordered_map<int, set<int>> coord;
        for (auto const &p : points) {
            coord[p[0]].insert(p[1]);
        }
        int res = INT_MAX;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            for (int j = 1; j < points.size(); j++) {
                int w = points[j][0], z = points[j][1];
                if (x == w || y == z)
                    continue;
                if (coord[x].count(z) && coord[w].count(y)) {
                    res = min(abs(w - x) * abs(z - y), res);
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end
