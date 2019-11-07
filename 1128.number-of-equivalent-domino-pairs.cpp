/*
 * @lc app=leetcode id=1128 lang=cpp
 *
 * [1128] Number of Equivalent Domino Pairs
 *
 * https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/
 *
 * algorithms
 * Easy (46.09%)
 * Likes:    93
 * Dislikes: 52
 * Total Accepted:    12.9K
 * Total Submissions: 27.9K
 * Testcase Example:  '[[1,2],[2,1],[3,4],[5,6]]'
 *
 * Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j]
 * = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that
 * is, one domino can be rotated to be equal to another domino.
 * 
 * Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length,
 * and dominoes[i] is equivalent to dominoes[j].
 * 
 * 
 * Example 1:
 * Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
 * Output: 1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= dominoes.length <= 40000
 * 1 <= dominoes[i][j] <= 9
 * 
 */

// @lc code=start
class Solution {
  public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes) {
        unordered_map<string, int> map;
        int res = 0;
        if (dominoes.empty()) {
            return res;
        }
        for (auto const d : dominoes) {
            string a;
            if (d[0] <= d[1]) {
                a.push_back(d[0] + '0');
                a.push_back(d[1] + '0');
            } else {
                a.push_back(d[1] + '0');
                a.push_back(d[0] + '0');
            }
            if (map.count(a) > 0) {
                res += map[a]++;
            } else {
                map[a] = 1;
            }
            cout << res << endl;
        }
        return res;
    }
};
// @lc code=end
