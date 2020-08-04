/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (36.91%)
 * Likes:    2707
 * Dislikes: 212
 * Total Accepted:    433.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> res;
        if (intervals.size() == 0) {
            return res;
        }
        auto cmp = [](vector<int> a, vector<int> b) { return a[0] > b[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (auto const &interval : intervals) {
            pq.push(interval);
        }
        vector<int> first = pq.top();
        pq.pop();
        while (pq.size() > 0) {
            auto second = pq.top();
            pq.pop();
            if (first[1] >= second[0]) {
                // if first inverval end time is greater than second start time which meand there is a overlap
                int start = first[0] < second[0] ? first[0] : second[0];
                int end = first[1] > second[1] ? first[1] : second[1];
                first = {start, end};
            } else {
                res.push_back(first);
                first = second;
            }
        }
        res.push_back(first);
        return res;
    }
};
// @lc code=end
