/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (47.21%)
 * Likes:    3079
 * Dislikes: 192
 * Total Accepted:    317.7K
 * Total Submissions: 671.8K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * Example 1:
 *
 *
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 *
 * Example 2:
 *
 *
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */
#include <algorithm>
#include <bitset>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
  int numSquares(int n) {
    static unordered_map<int, int> map_;

    if (map_.find(n) != map_.end()) {
      return map_[n];
    }

    if (n == 0) {
      return 0;
    }

    vector<int> squareSet;
    for (size_t i = 1; i * i <= n; i++) {
      squareSet.push_back(i * i);
    }

    if (squareSet.back() == n) {
      return 1;
    }

    unordered_set<int> q;
    q.insert(n);
    size_t res = 0;
    while (q.size() > 0) {
      res++;
      unordered_set<int> newQ;
      for (auto const &i : q) {
        for (auto const &s : squareSet) {
          //   cout << n << ' ' << s << endl;
          if (i == s) {
            return res;
          } else if (s > i) {
            // square is larger than n, no need for further iteration
            // e.g 16 > 9
            break;
          }
          newQ.insert(i - s);
        }
      }
      q = newQ;
    }
    map_[n] = res;
    return res;
  }
};
// @lc code=end
