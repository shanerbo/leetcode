/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 *
 * https://leetcode.com/problems/design-circular-queue/description/
 *
 * algorithms
 * Medium (41.25%)
 * Likes:    351
 * Dislikes: 60
 * Total Accepted:    40.2K
 * Total Submissions: 97.2K
 * Testcase Example:  '["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]\n' +
  '[[3],[1],[2],[3],[4],[],[],[],[4],[]]'
 *
 * Design your implementation of the circular queue. The circular queue is a
 * linear queue structure in which the operations are performed based on FIFO
 * (First In First Out) principle and the last position is connected back to
 * the first position to make a circle. It is also called "Ring Buffer".
 * 
 * One of the benefits of the circular queue is that we can make use of the
 * spaces in front of the queue. In a normal queue, once the queue becomes
 * full, we cannot insert the next element even if there is a space in front of
 * the queue. But using the circular queue, we can use the space to store new
 * values.
 * 
 * Your implementation should support following operations:
 * 
 * 
 * MyCircularQueue(k): Constructor, set the size of the queue to be k.
 * Front: Get the front item from the queue. If the queue is empty, return
 * -1.
 * Rear: Get the last item from the queue. If the queue is empty, return
 * -1.
 * enQueue(value): Insert an element into the circular queue. Return true if
 * the operation is successful.
 * deQueue(): Delete an element from the circular queue. Return true if the
 * operation is successful.
 * isEmpty(): Checks whether the circular queue is empty or not.
 * isFull(): Checks whether the circular queue is full or not.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to
 * be 3
 * circularQueue.enQueue(1);  // return true
 * circularQueue.enQueue(2);  // return true
 * circularQueue.enQueue(3);  // return true
 * circularQueue.enQueue(4);  // return false, the queue is full
 * circularQueue.Rear();  // return 3
 * circularQueue.isFull();  // return true
 * circularQueue.deQueue();  // return true
 * circularQueue.enQueue(4);  // return true
 * circularQueue.Rear();  // return 4
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All values will be in the range of [0, 1000].
 * The number of operations will be in the range of [1, 1000].
 * Please do not use the built-in Queue library.
 * 
 * 
 */

// @lc code=start
class MyCircularQueue {
  private:
    vector<int> queue;
    int head;
    int tail;
    int capacity;
    bool empty;

  public:
    MyCircularQueue(int k) : capacity(k), head(0), tail(0), queue(k), empty(true) {
    }

    bool enQueue(int value) {
        if (isFull())
            return false;
        if (head == tail && empty)
            empty = false;
        queue[tail] = value;
        tail = (tail + 1) % capacity;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;
        head = (head + 1) % capacity;
        if (head == tail && !empty)
            empty = true;
        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;
        return queue[head];
    }

    int Rear() {
        if (isEmpty())
            return -1;
        return queue[(tail + capacity - 1) % capacity];
    }

    bool isEmpty() {
        if (tail == head && empty)
            return true;
        return false;
    }

    bool isFull() {
        if (tail == head && !empty)
            return true;
        return false;
    }
};
// @lc code=end
