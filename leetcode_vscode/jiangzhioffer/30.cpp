#include <iostream>
#include <stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> dataStk, auxStk;
    MinStack() {
    }

    void push(int x) {
        dataStk.push(x);
        if (auxStk.empty()) {
            auxStk.push(x);
            return;
        }
        int curMin = auxStk.top();
        if (x < curMin) {
            auxStk.push(x);
        } else {
            auxStk.push(curMin);
        }
    }

    void pop() {
        dataStk.pop();
        auxStk.pop();
    }

    int top() {
        return dataStk.top();
    }

    int min() {
        return auxStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
int main() {

    system("pause");
    return 0;
}