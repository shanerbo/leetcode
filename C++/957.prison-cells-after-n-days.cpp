/*
 * @lc app=leetcode id=957 lang=cpp
 *
 * [957] Prison Cells After N Days
 *
 * https://leetcode.com/problems/prison-cells-after-n-days/description/
 *
 * algorithms
 * Medium (37.89%)
 * Likes:    215
 * Dislikes: 405
 * Total Accepted:    26.2K
 * Total Submissions: 68.4K
 * Testcase Example:  '[0,1,0,1,1,0,0,1]\n7'
 *
 * There are 8 prison cells in a row, and each cell is either occupied or
 * vacant.
 * 
 * Each day, whether the cell is occupied or vacant changes according to the
 * following rules:
 * 
 * 
 * If a cell has two adjacent neighbors that are both occupied or both vacant,
 * then the cell becomes occupied.
 * Otherwise, it becomes vacant.
 * 
 * 
 * (Note that because the prison is a row, the first and the last cells in the
 * row can't have two adjacent neighbors.)
 * 
 * We describe the current state of the prison in the following way: cells[i]
 * == 1 if the i-th cell is occupied, else cells[i] == 0.
 * 
 * Given the initial state of the prison, return the state of the prison after
 * N days (and N such changes described above.)
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: cells = [0,1,0,1,1,0,0,1], N = 7
 * Output: [0,0,1,1,0,0,0,0]
 * Explanation: 
 * The following table summarizes the state of the prison on each day:
 * Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
 * Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
 * Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
 * Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
 * Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
 * Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
 * Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
 * Day 7: [0, 0, 1, 1, 0, 0, 0, 0]
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
 * Output: [0,0,1,1,1,1,1,0]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * cells.length == 8
 * cells[i] is in {0, 1}
 * 1 <= N <= 10^9
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution1 {
  public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N) {
        // 00 -> 01 vacant -> occupied
        // 10 -> 11 occupied -> vacant
        // 10 -> 10 occupied -> occupied
        // 00 -> 00 vacant -> vacant
        if (N == 0) {
            return cells;
        }
        N = N % 14;
        if (N == 0) {
            N = 14;
        }

        for (int i = 0; i < N; ++i) {
            vector<int> res(8);
            for (int j = 0; j < 8; ++j) {
                if (j == 0 || j == 7) {
                    res[j] = 0;
                } else {
                    res[j] = cells[j - 1] + cells[j + 1] == 0 || cells[j - 1] + cells[j + 1] == 2 ? 1 : 0;
                }
            }
            cells = res;
        }
        return cells;
    }
};
class Solution {
  public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N) {
        if (N == 0) {
            return cells;
        }
        vector<int> res(8), patternTracker;
        for (int cycle = 0; N-- > 0; cycle++) {
            for (int j = 0; j < 8; ++j) {
                if (j == 0 || j == 7) {
                    res[j] = 0;
                } else {
                    res[j] = cells[j - 1] + cells[j + 1] == 0 || cells[j - 1] + cells[j + 1] == 2 ? 1 : 0;
                }
            }
            if (cycle == 0) {
                patternTracker = res;
            } else if (patternTracker == res) {
                N %= cycle;
            }
            cells = res;
        }
        return cells;
    }
};
// @lc code=end
