#include <iostream>
#include <stack>
using namespace std;
class MinStack {
private:
    stack<long long> dataStack;
    long long curMin;

public:
    MinStack() {
    }

    void push(int val) {
        if (dataStack.empty()) {
            dataStack.push(0);
            curMin = val;
            return;
        }
        long long sub = val - curMin;
        dataStack.push(sub);
        if (sub < 0) {
            curMin += sub;
        }
    }

    void pop() {
        if (dataStack.top() < 0) {
            curMin = curMin - dataStack.top();
        }
        dataStack.pop();
    }

    int top() {
        if (dataStack.top() < 0) {
            return curMin;
        }
        return curMin + dataStack.top();
    }

    int getMin() {
        return curMin;
    }
};
int main() {

    system("pause");
    return 0;
}