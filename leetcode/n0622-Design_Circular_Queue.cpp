#include <vector>
using namespace std;

class MyCircularQueue {
public:
    int beg, end, size, cap;
    vector<int> ele;

    int next(int cur){
        return (cur + 1)%cap;
    }

    int last(int cur){
        return (cur - 1 + cap) % cap;
    }

    MyCircularQueue(int k) {
        // [beg, end)
        ele.reserve(k);
        beg = 0;
        end = 0;
        size = 0;
        cap = k;
    }
    
    bool enQueue(int value) {
        if(isFull())return false;
        ele[end] = value;
        end = next(end);
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        beg = next(beg);
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty())return -1;
        return ele[beg];
    }
    
    int Rear() {
        if(isEmpty())return -1;
        return ele[last(end)];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */