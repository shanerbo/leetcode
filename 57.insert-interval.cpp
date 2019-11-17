/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (32.04%)
 * Likes:    1109
 * Dislikes: 139
 * Total Accepted:    205.3K
 * Total Submissions: 639.5K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        if (newInterval.empty() && intervals.empty() || newInterval.empty()) {
            return intervals;
        }
        if (intervals.empty()) {
            return {newInterval};
        }

        vector<vector<int>> res;
        int i = 0;
        for (; i < intervals.size() && intervals[i][1] < newInterval[0]; ++i) {
            res.push_back(intervals[i]);
        }
        auto first = newInterval;
        for (; i < intervals.size(); ++i) {
            auto second = intervals[i];
            if (first[1] >= second[0]) {
                // if first end time is greater than second starttime
                first[0] = first[0] <= second[0] ? first[0] : second[0];
                first[1] = first[1] <= second[1] ? second[1] : first[1];
            } else {
                res.push_back(first);
                first = second;
            }
        }
        res.emplace_back(first);
        return res;
    }
};
// @lc code=end
