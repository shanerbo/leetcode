/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 *
 * https://leetcode.com/problems/design-hashset/description/
 *
 * algorithms
 * Easy (56.58%)
 * Likes:    190
 * Dislikes: 50
 * Total Accepted:    31.1K
 * Total Submissions: 54.8K
 * Testcase Example:  '["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]\n[[],[1],[2],[1],[3],[2],[2],[2],[2]]'
 *
 * Design a HashSet without using any built-in hash table libraries.
 * 
 * To be specific, your design should include these functions:
 * 
 * 
 * add(value): Insert a value into the HashSet. 
 * contains(value) : Return whether the value exists in the HashSet or not.
 * remove(value): Remove a value in the HashSet. If the value does not exist in
 * the HashSet, do nothing.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MyHashSet hashSet = new MyHashSet();
 * hashSet.add(1);         
 * hashSet.add(2);         
 * hashSet.contains(1);    // returns true
 * hashSet.contains(3);    // returns false (not found)
 * hashSet.add(2);          
 * hashSet.contains(2);    // returns true
 * hashSet.remove(2);          
 * hashSet.contains(2);    // returns false (already removed)
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All values will be in the range of [0, 1000000].
 * The number of operations will be in the range of [1, 10000].
 * Please do not use the built-in HashSet library.
 * 
 * 
 */

// @lc code=start
class MyHashSet {
  private:
    struct Node {
        Node *next = nullptr;
        int val;
        Node(int v) : val(v) {}
    };
    // struct LL {
    //     Node *head = nullptr;
    //     Node *tail = nullptr;
    // }

  private:
    int hashKey = 1901;
    vector<Node *> hash;

  public:
    /** Initialize your data structure here. */
    MyHashSet() {
        hash = vector<Node *>(hashKey, nullptr);
        // hash = vector<LL *>(hashKey, nullptr);
    }

    void add(int key) {
        int hashValue = key % hashKey;

        if (hash[hashValue] != nullptr) {
            if (this->contains(key)) {
                return;
            }
            Node *newNode = new Node(key);
            Node **dummyHead = &hash[hashValue];
            while ((*dummyHead)->next) {
                dummyHead = &(*dummyHead)->next;
            }
            (*dummyHead)->next = newNode;

        } else {
            hash[hashValue] = new Node(key);
        }
    }

    void remove(int key) {
        int hashValue = key % hashKey;
        if (hash[hashValue] == nullptr) {
            return;
        }
        Node **dummyHead = &hash[hashValue];
        while ((*dummyHead)) {
            if ((*dummyHead)->val == key) {
                *dummyHead = (*dummyHead)->next;
                return;
            }
            dummyHead = &(*dummyHead)->next;
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hashValue = key % hashKey;
        if (hash[hashValue] == nullptr) {
            return false;
        }
        Node *dummyHead = hash[hashValue];
        while (dummyHead) {
            if (dummyHead->val == key) {
                return true;
            }
            dummyHead = dummyHead->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
