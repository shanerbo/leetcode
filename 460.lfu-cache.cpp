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
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
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
 * LFUCache cache = new LFUCache( 2 /* capacity */ );
//  *
//  * cache.put(1, 1);
//  * cache.put(2, 2);
//  * cache.get(1);       // returns 1
//  * cache.put(3, 3);    // evicts key 2
//  * cache.get(2);       // returns -1 (not found)
//  * cache.get(3);       // returns 3.
//  * cache.put(4, 4);    // evicts key 1.
//  * cache.get(1);       // returns -1 (not found)
//  * cache.get(3);       // returns 3
//  * cache.get(4);       // returns 4
//  *
//  *
//  *
//  *
//  */

// @lc code=start
class LFUCache {
  private:
    int Capacity;
    deque<pair<int, int>> dq;
    unordered_map < int,
        public : LFUCache(int capacity) {
    }

    int get(int key) {
    }

    void put(int key, int value) {
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
