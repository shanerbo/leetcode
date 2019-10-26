/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (49.82%)
 * Likes:    1361
 * Dislikes: 73
 * Total Accepted:    202.6K
 * Total Submissions: 404.7K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
  public:
    vector<int> rightSideView(TreeNode *root) {
        if (!root) {
            return {};
        }
        vector<int> res;
        deque<TreeNode *> queue;
        queue.push_back(root);
        while (queue.size() != 0) {
            res.push_back(queue.back()->val);
            int queSize = queue.size();
            for (int i = 0; i < queSize; i++) {
                if (queue[i]->left) {
                    queue.push_back(queue[i]->left);
                }
                if (queue[i]->right) {
                    queue.push_back(queue[i]->right);
                }
            }
            queue.erase(queue.begin(), queue.begin() + queSize);
        }
        return res;
    }
};
// @lc code=end
