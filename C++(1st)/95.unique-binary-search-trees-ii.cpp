/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (37.41%)
 * Likes:    1572
 * Dislikes: 130
 * Total Accepted:    158.5K
 * Total Submissions: 423K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  private:
    vector<TreeNode *> generateTree(int s, int e) {
        if (s > e) {
            return {nullptr};
        }
        if (s == e) {
            return {new TreeNode(e)};
        }

        vector<TreeNode *> res;
        for (int i = s; i <= e; i++) {
            for (auto const &l : generateTree(s, i - 1)) {
                for (auto const &r : generateTree(i + 1, e)) {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

  public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return generateTree(1, n);
    }
};
// @lc code=end
