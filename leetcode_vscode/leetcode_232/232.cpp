#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
    stack<int> stk1, stk2;
    MyQueue() {
    }

    void push(int x) {
        stk1.push(x);
    }

    int pop() {
        if (!stk2.empty()) {
            int res = stk2.top();
            stk2.pop();
            return res;
        }
        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        if (stk2.empty()) { // stk1与stk2皆为空，队列也就为空
            return -1;
        }
        int res = stk2.top();
        stk2.pop();
        return res;
    }

    int peek() {
        if (!stk2.empty()) {
            return stk2.top();
        }
        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        if (stk2.empty()) { // stk1与stk2皆为空，队列也就为空
            return -1;
        }
        return stk2.top();
    }

    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */