/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (29.20%)
 * Likes:    1924
 * Dislikes: 502
 * Total Accepted:    285.6K
 * Total Submissions: 975.9K
 * Testcase Example:
 * '{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}'
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 *
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input:
 *
 * {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
 *
 * Explanation:
 * Node 1's value is 1, both of its next and random pointer points to Node 2.
 * Node 2's value is 2, its next pointer points to null and its random pointer
 * points to itself.
 *
 *
 *
 *
 * Note:
 *
 *
 * You must return the copy of the given head as a reference to the cloned
 * list.
 *
 *
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return head;
        } else {
            unordered_map<Node*, Node*> map;
            auto dummyHead = head;
            // set up a hash map
            while (dummyHead) {
                auto* newNode = new Node(dummyHead->val);
                map[dummyHead] = newNode;
                dummyHead = dummyHead->next;
            }
            for (auto& node : map) {
                auto original = node.first;
                auto copy = node.second;
                copy->next = map[original->next];
                copy->random = map[original->random];
                cout << map.size();
            }
            return map.begin()->first;
        }
    }
};
// @lc code=end
