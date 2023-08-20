#include <iostream>
#include <unordered_map>
using namespace std;

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int capacity;
    int size;

public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.count(key)) {
            moveToHead(cache[key]);
            return cache[key]->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            cache[key]->value = value;
            moveToHead(cache[key]);
        } else {
            cache[key] = new DLinkedNode(key, value);
            addToHead(cache[key]);
            size++;
            if (size > capacity) {
                DLinkedNode* node = removeTail();
                cache.erase(node->key);
                delete node;
                size--;
            }
        }
    }

    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addToHead(DLinkedNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }
    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }
    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};
int main() {

    system("pause");
    return 0;
}