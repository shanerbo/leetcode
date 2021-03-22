/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 *
 * https://leetcode.com/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (60.57%)
 * Likes:    2850
 * Dislikes: 175
 * Total Accepted:    252K
 * Total Submissions: 415.9K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * There are n cities. Some of them are connected, while some are not. If city
 * a is connected directly with city b, and city b is connected directly with
 * city c, then city a is connected indirectly with city c.
 *
 * A province is a group of directly or indirectly connected cities and no
 * other cities outside of the group.
 *
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
 * i^th city and the j^th city are directly connected, and isConnected[i][j] =
 * 0 otherwise.
 *
 * Return the total number of provinces.
 *
 *
 * Example 1:
 *
 *
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 200
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] is 1 or 0.
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
 *
 *
 */
#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
// @lc code=start
class Solution {
private:
  void helper(vector<vector<int>> &grid, vector<char> &v, const int &pos) {
    if (v[pos] == '1') {
      return;
    }
    v[pos] = '1';
    for (int i = 0; i < grid[pos].size(); ++i) {
      if (grid[pos][i] != 0) {
        helper(grid, v, i);
      }
    }
  }

public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size(); // number of cities
    vector<char> visited(n, '0');
    int res = 0;
    if (n == 0) {
      return 0;
    }
    for (int i = 0; i < visited.size(); ++i) {
      auto v = visited[i];
      if (v != '1') {
        helper(isConnected, visited, i);
        res++;
      }
    }
    return res;
  }
};
// @lc code=end
