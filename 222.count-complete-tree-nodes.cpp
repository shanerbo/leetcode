/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (38.11%)
 * Likes:    1384
 * Dislikes: 158
 * Total Accepted:    161K
 * Total Submissions: 414.1K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given a complete binary tree, count the number of nodes.
 * 
 * Note: 
 * 
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2^h nodes inclusive at the last level
 * h.
 * 
 * Example:
 * 
 * 
 * Input: 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠/ \  /
 * 4  5 6
 * 
 * Output: 6
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
    int countNodes(TreeNode* root) {
        int res = 0;
        if(!root){
            return res;
        }
        queue<TreeNode*> queue;
        queue.push(root);
        res++;
        while(!queue.empty()){
            int size = queue.size();
            for(int i = 0; i < size; ++i){
                auto tmp = queue.front();queue.pop();
                if(tmp->left){
                    res++;
                    queue.push(tmp->left);
                }else{
                    return res;
                }
                if(tmp->right){
                    res++;
                    queue.push(tmp->right);
                }
            }
        }
        return res;
    }
};
// @lc code=end

