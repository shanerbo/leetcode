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
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        if (!root) {
            return nullptr;
        }
        TreeNode *res = nullptr;

        if (p->right) {
            auto tmp = p->right;
            while (tmp) {
                res = tmp;
                tmp = tmp->left;
            }
            return res;
        }
        while (root) {
            if (root->val > p->val) {
                res = root;
                root = root->left;
            } else if (root->val < p->val) {
                root = root->right;
            } else {
                break;
            }
        }
        return res;
    }
};
