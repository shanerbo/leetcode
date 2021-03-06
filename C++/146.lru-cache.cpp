/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (27.69%)
 * Likes:    3701
 * Dislikes: 152
 * Total Accepted:    362K
 * Total Submissions: 1.3M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * The cache is initialized with a positive capacity.
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * 
 * LRUCache cache = new LRUCache( 2 /* capacity */ );
**cache.put(1, 1);
*cache.put(2, 2);
*cache.get(1);    // returns 1
*cache.put(3, 3); // evicts key 2
*cache.get(2);    // returns -1 (not found)
*cache.put(4, 4); // evicts key 1
*cache.get(1);    // returns -1 (not found)
*cache.get(3);    // returns 3
*cache.get(4);    // returns 4
***** /
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
    struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
// @lc code=start
class LRUCache {
private:
  size_t cap{0};
  list<int> lst;
  unordered_map<int, int> map;
  unordered_map<int, list<int>::iterator> key_it;

public:
  LRUCache(int capacity) : cap(capacity) {}

  int get(int key) {
    if (map.find(key) == map.end()) {
      return -1;
    }
    auto it = key_it[key];
    lst.erase(it);
    lst.push_back(key);
    key_it[key] = --lst.end();
    return map[key];
  }

  void put(int key, int value) {
    if (get(key) != -1) {
      // update key
      map[key] = value;
      return;
    }
    if (map.size() >= cap) {
      // evict
      auto it = lst.front();
      map.erase(it);
      key_it.erase(it);
      lst.pop_front();
    }
    map[key] = value;
    lst.push_back(key);
    key_it[key] = --lst.end();
    return;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
