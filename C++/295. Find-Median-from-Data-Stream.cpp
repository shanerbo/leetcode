class MedianFinder {
  private:
    priority_queue<int, vector<int>, less<int>> smaller;
    priority_queue<int, vector<int>, greater<int>> bigger;

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
        if (smaller.size() + 1 < bigger.size()) {
            smaller.push(bigger.top());
            bigger.pop();
        } else if (bigger.size() + 1 < smaller.size()) {
            bigger.push(smaller.top());
            smaller.pop();
        }
    }

    double findMedian() {
        if (smaller.empty() && bigger.empty()) {
            return 0.0;
        }
        if (smaller.empty() || smaller.size() < bigger.size()) {
            return bigger.top();
        }
        if (bigger.empty() || bigger.size() < smaller.size()) {
            return smaller.top();
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