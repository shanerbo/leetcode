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
    int minFreq;
    unordered_map<int, pair<int, int>> keyValueMap;   // key => <value, freq>
    unordered_map<int, list<int>> freqMap;            // freq => list of keys
    unordered_map<int, list<int>::iterator> keyItMap; // key => it
  public:
    LFUCache(int capacity) : Capacity(capacity) {
    }

    int get(int key) {
        if (keyValueMap.find(key) == keyValueMap.end()) {
            // key does not exist in the table
            return -1;
        }
        int value = keyValueMap[key].first;
        int freq = keyValueMap[key].second++;
        auto it = keyItMap[key];
        freqMap[freq].erase(it);
        // if current key has the lowest frequency, and there is no other key has
        // has same freq number,then we have to increment freq by 1
        if (freq == minFreq && freqMap[freq].empty()) {
            minFreq++;
        }
        freqMap[++freq].push_back(key);
        list<int>::iterator newIt = --freqMap[freq].end();

        keyItMap[key] = newIt;
        return value;
    }

    void put(int key, int value) {
        if (Capacity <= 0) {
            return;
        }
        if (get(key) != -1) {
            keyValueMap[key].first = value;
            return;
        }

        // update key value pair
        if (keyValueMap.size() >= Capacity) {
            // we need to evict a page
            int keyToBeMoved = freqMap[minFreq].front();

            freqMap[minFreq].pop_front();
            auto it = keyItMap[keyToBeMoved];

            keyValueMap.erase(keyToBeMoved);
            // freqMap[key].erase(it);
        }
        // insert new key
        minFreq = 1;
        keyValueMap[key] = make_pair(value, 1);

        freqMap[1].push_back(key);
        keyItMap[key] = --freqMap[1].end();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
