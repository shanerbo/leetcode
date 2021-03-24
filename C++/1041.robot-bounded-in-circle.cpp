/*
 * @lc app=leetcode id=1041 lang=cpp
 *
 * [1041] Robot Bounded In Circle
 *
 * https://leetcode.com/problems/robot-bounded-in-circle/description/
 *
 * algorithms
 * Medium (55.08%)
 * Likes:    957
 * Dislikes: 289
 * Total Accepted:    64.8K
 * Total Submissions: 117.6K
 * Testcase Example:  '"GGLLGG"'
 *
 * On an infinite plane, a robot initially stands at (0, 0) and faces north.
 * The robot can receive one of three instructions:
 *
 *
 * "G": go straight 1 unit;
 * "L": turn 90 degrees to the left;
 * "R": turn 90 degrees to the right.
 *
 *
 * The robot performs the instructions given in order, and repeats them
 * forever.
 *
 * Return true if and only if there exists a circle in the plane such that the
 * robot never leaves the circle.
 *
 *
 * Example 1:
 *
 *
 * Input: instructions = "GGLLGG"
 * Output: true
 * Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and
 * then returns to (0,0).
 * When repeating these instructions, the robot remains in the circle of radius
 * 2 centered at the origin.
 *
 * Example 2:
 *
 *
 * Input: instructions = "GG"
 * Output: false
 * Explanation: The robot moves north indefinitely.
 *
 * Example 3:
 *
 *
 * Input: instructions = "GL"
 * Output: true
 * Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) ->
 * (0, 0) -> ...
 *
 *
 * Constraints:
 *
 *
 * 1 <= instructions.length <= 100
 * instructions[i] is 'G', 'L' or, 'R'.
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
public:
  bool isRobotBounded(string instructions) {
    int x = 0, y = 0, face = 0, dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (auto const &c : instructions) {
      if (c == 'R') {
        face = (face + 1) % 4;
      } else if (c == 'L') {
        face = (face + 3) % 4;
      } else {
        x += dirs[face][0];
        y += dirs[face][1];
      }
    }
    if (x == 0 and y == 0) {
      return true;
    }
    return face != 0;
  }
};
// @lc code=end
