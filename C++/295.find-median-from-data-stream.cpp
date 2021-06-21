/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
#include <queue>
using namespace std;
class MedianFinder {

  public:
    /** initialize your data structure here. */
    MedianFinder() : size() {
    }

    void addNum(int num) {
        size++;
        if (max_heap.size() > 0 && num >= max_heap.top()) {
            min_heap.push(num);
        } else {
            max_heap.push(num);
        }
        if (min_heap.size() > max_heap.size() + 1) {
            auto top = min_heap.top();
            max_heap.push(top);
            min_heap.pop();
        } else if (max_heap.size() > min_heap.size() + 1) {
            auto top = max_heap.top();
            min_heap.push(top);
            max_heap.pop();
        }
    }

    double findMedian() {
        if (size == 0) {
            return 0;
        }
        if (size & 1 == 1) { //odd
            return max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
        } else {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
    }

  private:
    priority_queue<double, vector<double>> max_heap;
    priority_queue<double, vector<double>, std::greater<double>> min_heap;
    size_t size;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
