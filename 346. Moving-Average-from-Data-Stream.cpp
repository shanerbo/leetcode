class MovingAverage {
  private:
    queue<int> _q;
    int _size;
    int _total;

  public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : _size(size), _total(0) {
    }

    double next(int val) {
        if (_q.size() >= _size) {
            _total -= _q.front();
            _q.pop();
            _q.push(val);
            _total += val;
        } else {
            _total += val;
            _q.push(val);
        }
        double res = 1.0 * _total / _q.size();
        return res;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */