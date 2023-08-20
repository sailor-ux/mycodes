#include <iostream>
#include <stack>
using namespace std;
class CQueue {
public:
    stack<int> stk1, stk2;
    CQueue() {
    }

    void appendTail(int value) {
        stk1.push(value);
    }

    int deleteHead() {
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
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
int main() {

    system("pause");
    return 0;
}