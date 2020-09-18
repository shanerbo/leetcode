/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (36.26%)
 * Likes:    1880
 * Dislikes: 504
 * Total Accepted:    97.7K
 * Total Submissions: 268.5K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given a binary tree, find the length of the longest path where each node in
 * the path has the same value. This path may or may not pass through the
 * root.
 *
 * The length of path between two nodes is represented by the number of edges
 * between them.
 *
 *
 *
 * Example 1:
 *
 * Input:
 *
 *
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 *
 *
 * Output: 2
 *
 *
 *
 * Example 2:
 *
 * Input:
 *
 *
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 *
 *
 * Output: 2
 *
 *
 *
 * Note: The given binary tree has not more than 10000 nodes. The height of the
 * tree is not more than 1000.
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
  int helper(TreeNode *root, int &m) {
    if (!root) {
      return 0;
    }
    int l = helper(root->left, m);
    int r = helper(root->right, m);
    if (root->left && root->left->val == root->val && root->right &&
        root->right->val == root->val) {
      m = max(m, l + r + 2);
      return max(l + 1, r + 1);
    } else if (root->left && root->left->val == root->val) {
      m = max(m, l + 1);
      return l + 1;
    } else if (root->right && root->right->val == root->val) {
      m = max(m, r + 1);
      return r + 1;
    } else {
      return 0;
    }
  }

public:
  int longestUnivaluePath(TreeNode *root) {
    int res = 0;
    helper(root, res);
    return res;
  }
};
// @lc code=end
