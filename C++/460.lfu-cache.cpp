/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 *
 * https://leetcode.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (30.58%)
 * Likes:    893
 * Dislikes: 90
 * Total Accepted:    51.1K
 * Total Submissions: 166.1K
 * Testcase Example:
 '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Frequently Used (LFU) cache.
 * It should support the following operations: get and put.
 *
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reaches its capacity, it should invalidate the least
 * frequently used item before inserting a new item. For the purpose of this
 * problem, when there is a tie (i.e., two or more keys that have the same
 * frequency), the least recently used key would be evicted.
 *
 * Note that the number of times an item is used is the number of calls to the
 * get and put functions for that item since it was inserted. This number is
 * set to zero when the item is removed.
 *
 *
 *
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 *
 *
 *
 * Example:
 *
 *
 * LFUCache cache = new LFUCache( 2 /* capacity );
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.get(3);       // returns 3.
 * cache.put(4, 4);    // evicts key 1.
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 *
 *
 *
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
class LFUCache {
private:
  unordered_map<int, pair<int, int>> key_value_freq_map;
  unordered_map<int, vector<int>> freq_key_map;
  unordered_map<int, vector<int>::iterator> key_it_map;
  int lowest_freq;
  int size;

public:
  LFUCache(int capacity) : lowest_freq(0), size(capacity) {}

  int get(int key) {
    auto it = key_value_freq_map.find(key);
    if (it == key_value_freq_map.end()) {
      // no such key
      return -1;
    }
    auto value_freq = key_value_freq_map[key];
    int freq = value_freq.second;
    int value = value_freq.first;
    auto key_it = key_it_map[key];
    auto key_list = freq_key_map[freq];
    freq_key_map[freq].erase(key_it);
    if (freq_key_map[freq].empty()) {
      lowest_freq++;
    }
    freq++;
    freq_key_map[freq].push_back(key);
    key_value_freq_map[key] = {value, freq};
    key_it_map[key] = --freq_key_map[freq].end();
    return value;
  }

  void put(int key, int value) {
    if (size <= 0) {
      return;
    }
    if (get(key) != -1) { // update
      key_value_freq_map[key].first = value;
      return;
    }
    // insert
    if (key_value_freq_map.size() >= size) {
      // evict
      auto low_key_it = freq_key_map[lowest_freq].begin();
      int low_key = *low_key_it;
      key_value_freq_map.erase(low_key);
      key_it_map.erase(low_key);
      freq_key_map[lowest_freq].erase(freq_key_map[lowest_freq].begin());
      size--;
    }
    key_value_freq_map[key] = {value, 1};
    freq_key_map[1].push_back(key);
    key_it_map[key] = --freq_key_map[1].end();
    lowest_freq = 1;
    size++;
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
