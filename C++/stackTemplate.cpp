template <class T>

class myStack {
  private:
    vector<T> stack;

  public:
    myStack() {}
    T peek() {
        if (this->stack.empty()) {
            T res{};
            return res;
        }
        cout << stack.back() << endl;
        return stack.back();
    }
    void push(T key) {
        stack.push_back(key);
    }
    void pop() {
        stack.pop_back();
    }
};
