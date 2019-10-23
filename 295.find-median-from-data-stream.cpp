/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (38.99%)
 * Likes:    1519
 * Dislikes: 30
 * Total Accepted:    133.7K
 * Total Submissions: 342.4K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n[[],[1],[2],[],[3],[]]'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * For example,
 * 
 * [2,3,4], the median is 3
 * 
 * [2,3], the median is (2 + 3) / 2 = 2.5
 * 
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addNum(int num) - Add a integer number from the data stream to the data
 * structure.
 * double findMedian() - Return the median of all elements so far.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * If all integer numbers from the stream are between 0 and 100, how would you
 * optimize it?
 * If 99% of all integer numbers from the stream are between 0 and 100, how
 * would you optimize it?
 * 
 * 
 */

// @lc code=start
class MedianFinder {
  private:
    priority_queue<int, vector<int>, less<int>> smaller;   // min heap
    priority_queue<int, vector<int>, greater<int>> bigger; // max heap

  public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        if (smaller.size() != 0 && num > smaller.top()) {
            bigger.push(num);
        } else {
            smaller.push(num);
        }
        balanceHeaps();
    }
    void balanceHeaps() {
        if (bigger.size() > smaller.size() + 1) {
            smaller.push(bigger.top());
            bigger.pop();
        } else if (smaller.size() > bigger.size() + 1) {
            bigger.push(smaller.top());
            smaller.pop();
        }
    }

    double findMedian() {
        if (smaller.size() == 0 && bigger.size() == 0) {
            return 0.0;
        }
        if (bigger.empty() || smaller.size() > bigger.size()) {
            return smaller.top();
        }
        if (smaller.empty() || smaller.size() < bigger.size()) {
            return bigger.top();
        } else {
            return (smaller.top() + bigger.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
