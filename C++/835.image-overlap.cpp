/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 *
 * https://leetcode.com/problems/image-overlap/description/
 *
 * algorithms
 * Medium (58.51%)
 * Likes:    507
 * Dislikes: 705
 * Total Accepted:    40.5K
 * Total Submissions: 64.7K
 * Testcase Example:  '[[1,1,0],[0,1,0],[0,1,0]]\n[[0,0,0],[0,1,1],[0,0,1]]'
 *
 * Two images A and B are given, represented as binary, square matrices of the
 * same size.  (A binary matrix has only 0s and 1s as values.)
 *
 * We translate one image however we choose (sliding it left, right, up, or
 * down any number of units), and place it on top of the other image.  After,
 * the overlap of this translation is the number of positions that have a 1 in
 * both images.
 *
 * (Note also that a translation does not include any kind of rotation.)
 *
 * What is the largest possible overlap?
 *
 * Example 1:
 *
 *
 * Input: A = [[1,1,0],
 * ⁠           [0,1,0],
 * [0,1,0]]
 * B = [[0,0,0],
 * [0,1,1],
 * [0,0,1]]
 * Output: 3
 * Explanation: We slide A to right by 1 unit and down by 1 unit.
 *
 * Notes: 
 *
 *
 * 1 <= A.length = A[0].length = B.length = B[0].length <= 30
 * 0 <= A[i][j], B[i][j] <= 1
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

using namespace std;
// @lc code=start
class Solution {
public:
  int countOverlap(vector<vector<int>> &a, vector<vector<int>> &b, int shiftX,
                   int shiftY) {
    if (shiftX >= a.size() || shiftY >= a.size()) {
      return 0;
    }
    int max = 0;
    for (size_t i = 0; i + shiftX < a.size(); i++) {
      for (size_t j = 0; j + shiftY < a.size(); j++) {
        if (a[i][j] == b[i + shiftX][j + shiftY] && a[i][j] == 1) {
          max++;
        }
      }
    }
    return max;
  }

  int countOverlapR(vector<vector<int>> &a, vector<vector<int>> &b, int shiftX,
                    int shiftY) {
    if (abs(shiftX) >= a.size() || abs(shiftY) >= a.size()) {
      return 0;
    }
    int max = 0;
    for (int i = 0; i < a.size() && i + shiftX < a.size(); ++i) {
      for (int j = a.size() - 1; j >= 0 && j + shiftY >= 0; j--) {
        if (a[i][j] == b[i + shiftX][j + shiftY] && a[i][j] == 1) {
          max++;
        }
      }
    }
    return max;
  }

  int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B) {
    int max = 0;
    for (int i = 0; i < A.size(); i++) {
      for (size_t j = 0; j < A.size(); j++) {
        max = std::max(max, countOverlap(A, B, i, j));
        max = std::max(max, countOverlap(B, A, i, j));
        max = std::max(max, countOverlapR(B, A, i, -1 * j));
        max = std::max(max, countOverlapR(A, B, i, -1 * j));
      }
    }
    return max;
  }
};
// @lc code=end
