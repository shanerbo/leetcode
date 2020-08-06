/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (41.04%)
 * Likes:    2023
 * Dislikes: 507
 * Total Accepted:    486.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given the below binary tree and sum = 22,
 *
 *
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \      \
 * 7    2      1
 *
 *
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 *
 */
#include <algorithm>
#include <bitset>
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
public:
  bool hasPathSum(TreeNode *root, int sum) { return helper(root, sum, 0); }

  bool helper(TreeNode *root, int sum, int preSum) {
    if (root && root->val + preSum == sum && !root->left && !root->right) {
      return true;
    } else if ((root && root->val + preSum != sum && !root->left &&
                !root->right) ||
               !root) {
      return false;
    }
    bool left = false;
    bool right = false;
    if (root->left) {
      left = helper(root->left, sum, preSum + root->val);
    }
    if (root->right) {
      right = helper(root->right, sum, preSum + root->val);
    }
    return left || right;
  }
};
// @lc code=end
