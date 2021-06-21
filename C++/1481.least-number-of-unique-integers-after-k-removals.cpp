/*
 * @lc app=leetcode id=1481 lang=cpp
 *
 * [1481] Least Number of Unique Integers after K Removals
 */

// @lc code=start
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
  public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
        if (arr.size() == 0) {
            return 0;
        }
        list<int> lst;
        unordered_map<int, int> kv;
        for (auto const &a : arr) {
            kv[a]++;
        }
        for (auto const &k : kv) {
            lst.push_back(k.second);
        }
        lst.sort();
        while (k > 0) {
            if (k < lst.front()) {
                k = 0;
            } else {
                k -= lst.front();
                lst.pop_front();
            }
        }
        return lst.size();
    }
};
// @lc code=end
