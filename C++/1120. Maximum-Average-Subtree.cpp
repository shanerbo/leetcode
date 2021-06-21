/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  private:
    double res = 0; // maximum

  public:
    double maximumAverageSubtree(TreeNode *root) {
        dfs(root);
        return res;
    }
    /**
    * pair[num, sum]
    */
    pair<int, int> dfs(TreeNode *root) {
        if (!root) {
            return {0, 0};
        }

        auto left = dfs(root->left);

        auto right = dfs(root->right);
        res = max(res, static_cast<double>((left.second + right.second + root->val) * 1.0 / (left.first + right.first + 1)));
        if (left.first > 0) {

            res = max(res, static_cast<double>(left.second * 1.0 / left.first));
        }
        if (right.first > 0) {

            res = max(res, static_cast<double>(right.second * 1.0 / right.first));
        }
        return {left.first + right.first + 1, left.second + right.second + root->val};
    }
};