/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
 *
 * algorithms
 * Medium (44.91%)
 * Likes:    2105
 * Dislikes: 145
 * Total Accepted:    371.1K
 * Total Submissions: 822.3K
 * Testcase Example:  '[1,2,3,4,5,6,7]'
 *
 * You are given a perfect binary tree where all leaves are on the same level,
 * and every parent has two children. The binary tree has the following
 * definition:
 *
 *
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 *
 *
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 *
 *
 * Follow up:
 *
 *
 * You may only use constant extra space.
 * Recursive approach is fine, you may assume implicit stack space does not
 * count as extra space for this problem.
 *
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: root = [1,2,3,4,5,6,7]
 * Output: [1,#,2,3,#,4,5,6,7,#]
 * Explanation: Given the above perfect binary tree (Figure A), your function
 * should populate each next pointer to point to its next right node, just like
 * in Figure B. The serialized output is in level order as connected by the
 * next pointers, with '#' signifying the end of each level.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the given tree is less than 4096.
 * -1000 <= node.val <= 1000
 *
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
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node *connect(Node *root) {
    /*
     * bfs
     */
    if (!root) {
      return root;
    }

    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      auto prev = q.front();
      q.pop();
      size_t size = q.size();
      if (!size) {
        prev->next = nullptr;
      }
      if (prev->left) {
        q.push(prev->left);
      }
      if (prev->right) {
        q.push(prev->right);
      }
      for (size_t i = 1; i <= size; i++) {
        auto curr = q.front();
        cout << curr->val;
        q.pop();
        prev->next = curr;

        if (i == size) {
          curr->next = nullptr;
        } else {
          prev = curr;
        }
        if (curr->left) {
          q.push(curr->left);
        }
        if (curr->right) {
          q.push(curr->right);
        }
      }
    }
    return root;
  }
};
// @lc code=end
