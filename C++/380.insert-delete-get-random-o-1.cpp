/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;
class RandomizedSet {
 private:
  unordered_map<int, int> map_;
  vector<int> list_;

 public:
  /** Initialize your data structure here. */
  RandomizedSet() : map_(), list_() {}

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (map_.find(val) != map_.end()) {
      return false;
    }
    list_.push_back(val);
    map_[val] = list_.size() - 1;
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (map_.find(val) == map_.end()) {
      return false;
    }
    int last = list_.back();
    list_[map_[val]] = last;
    map_[last] = map_[val];
    list_.pop_back();
    map_.erase(val);
    return true;
  }
  /** Get a random element from the set. */
  int getRandom() { return list_[rand() % list_.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
