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
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
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
//  * LRUCache cache = new LRUCache( 2 /* capacity */
//);
//  *
//  * cache.put(1, 1);
//  * cache.put(2, 2);
//  * cache.get(1);       // returns 1
//  * cache.put(3, 3);    // evicts key 2
//  * cache.get(2);       // returns -1 (not found)
//  * cache.put(4, 4);    // evicts key 1
//  * cache.get(1);       // returns -1 (not found)
//  * cache.get(3);       // returns 3
//  * cache.get(4);       // returns 4
//  *
//  *
//  *
//  *
//  */

// @lc code=start
class LRUCache {
  private:
    int timer;
    unordered_map<int, Record *> db;
    class Record {
      private:
        int key;
        int value;
        int time;

      public:
        Record(int _key, int _value, int _time) : key(_key), value(_value), time(_time) {}
    };

  public:
    LRUCache(int capacity) {
        }

    int get(int key) {
    }

    void put(int key, int value) {
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
