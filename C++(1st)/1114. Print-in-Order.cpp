class Foo {
  private:
    mutex mtx;
    condition_variable cv;
    bool ready = false;
    int order = 0;

  public:
    Foo() {
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> latch(mtx);
        printFirst();
        order++;
        latch.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> latch(mtx);
        cv.wait(latch, [=] { return order == 1; });
        printSecond();
        order++;
        latch.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> latch(mtx);
        cv.wait(latch, [=] { return order == 2; });
        printThird();
        latch.unlock();
        cv.notify_all();
    }
};