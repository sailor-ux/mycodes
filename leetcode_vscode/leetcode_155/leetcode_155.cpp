#include <iostream>
#include <stack>
using namespace std;
// ���в����ö���Ŀռ䣬��ʹ�ø���ջ�ķ���������
// https://blog.csdn.net/weixin_44891861/article/details/121193861
class MinStack {
private:
    stack<int> dataStack;
    stack<int> minStack; // ����ջ

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