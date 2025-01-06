#include <unordered_map>

using namespace std;

class DLinkNode {
    // use double link list for quickly remove node
    public:
    int key;
    int value;
    DLinkNode * next;
    DLinkNode * prev;
    DLinkNode(int key, int value, DLinkNode * next = nullptr, DLinkNode * prev = nullptr){
        this->key = key;
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
    ~DLinkNode(){
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, DLinkNode *> k2n; // key to node
    DLinkNode * dummyHead;
    DLinkNode * dummyTail;
    int capacity;
    int size;

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->dummyHead = new DLinkNode(0, 0);
        this->dummyTail = new DLinkNode(0, 0);
        this->dummyHead->next = this->dummyTail;
        this->dummyTail->prev = this->dummyHead;
    }

    void removeLRU() {
        DLinkNode * LRU = dummyTail->prev;
        k2n.erase(LRU->key);
        LRU->prev->next = LRU->next;
        LRU->next->prev = LRU->prev;
        delete LRU;
    }

    void moveToHead(DLinkNode * used) {
        if (used->next != nullptr) used->next->prev = used->prev;
        if (used->prev != nullptr) used->prev->next = used->next;

        used->next = dummyHead->next;
        used->prev = dummyHead;
        used->next->prev = used;
        used->prev->next = used;     
    }


    
    int get(int key) {
        if (!k2n.count(key)) return -1;
        moveToHead(k2n[key]);
        return k2n[key]->value;
    }
    
    void put(int key, int value) {
        if (k2n.count(key)) {
            k2n[key]->value = value;
            moveToHead(k2n[key]);
            return;
        }

        if (size == capacity) {
            removeLRU();
        } else{
            size ++;
        }

        DLinkNode * newNode = new DLinkNode(key, value);
        k2n[key] = newNode;
        moveToHead(newNode);

    }
};