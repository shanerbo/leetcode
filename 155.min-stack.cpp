/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (38.97%)
 * Likes:    2164
 * Dislikes: 235
 * Total Accepted:    356.2K
 * Total Submissions: 911.9K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class MinStack {
  private:
    vector<int> _stack; // even though there is stack type.
    vector<int> _min;
    int _min;

  public:
    /** initialize your data structure here. */
    MinStack() {
        this->setMin(INT_MAX);
    }

    void setMin(int x) {
        this->_min = x;
    }

    void push(int x) {
        this->_stack.push_back(x);
        if (_min.back() >= x) {
            _min.push_back(x);
        }
    }

    void pop() {
        if (this->top == _min.back()) {
            _stack.pop_back();
            _min.pop_back();
        } else {
            _stack.pop_back();
        }
    }

    int top() {
        return _stack.back();
    }

    int getMin() {
        return _min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
