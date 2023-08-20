#include <iostream>
#include <stack>
using namespace std;
// 还有不利用额外的空间，不使用辅助栈的方法！！！
// https://blog.csdn.net/weixin_44891861/article/details/121193861
class MinStack {
private:
    stack<int> dataStack;
    stack<int> minStack; // 辅助栈

public:
    MinStack() {
    }

    void push(int val) {
        dataStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (dataStack.top() == minStack.top()) {
            minStack.pop();
        }
        dataStack.pop();
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};
int main() {

    system("pause");
    return 0;
}