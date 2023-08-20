#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
    stack<int> stk1, stk2;
    MyQueue() {
    }

    void push(int x) {
        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk1.push(x);
        while (!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }

    int pop() {
        int x = stk1.top();
        stk1.pop();
        return x;
    }

    int peek() {
        return stk1.top();
    }

    bool empty() {
        return stk1.empty();
    }
};
int main() {

    system("pause");
    return 0;
}