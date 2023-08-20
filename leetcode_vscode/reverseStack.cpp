#include <iostream>
#include <stack>
using namespace std;
// 用递归反转栈，不用其他数据结构
int getAndDelLastElem(stack<int>& s);
void reverse(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    int i = getAndDelLastElem(s); // 拿到栈底的元素，并删除栈底元素
    reverse(s);
    s.push(i); // 再将栈底元素放进栈顶
}
int getAndDelLastElem(stack<int>& s) {
    int result = s.top();
    s.pop();
    if (s.empty()) {
        return result;
    }
    int last = getAndDelLastElem(s);
    s.push(result);
    return last;
}
int main() {

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reverse(s);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    system("pause");
    return 0;
}