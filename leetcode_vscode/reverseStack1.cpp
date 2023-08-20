#include <iostream>
#include <stack>
using namespace std;
// 递归的最后一层是栈内仅剩栈底元素一个元素，相当于递归的最后一层向前移一位，递归的最后一层往外层移一层
// 因为要将栈底元素一路带回去一路返回return，所以递归的最后一层就是栈内仅剩栈底元素
// 如果是最普通的递归，递归的最后一层是栈为空，那么栈最终还会恢复成最原来的样子，无法做到删除栈底元素；并且函数将无法拥有返回值，函数将变成没有返回值，那么也就无法将栈底元素一路带回去
// 递的过程：不断出栈；归的过程：将刚才弹栈的元素又入栈，并且将栈底元素一路带回去
int getAndDelLastElem(stack<int>& stk) { // 获取并删除栈底元素
    int val = stk.top();
    stk.pop();
    if (stk.empty()) { // 递归的出口，对应栈内仅剩下一个栈底元素
        return val;
    }
    int bottom = getAndDelLastElem(stk);
    stk.push(val);
    return bottom;
}
void reverse(stack<int>& stk) { // 这是最普通最基本的递归。递归的最后一层，就是栈为空
    if (stk.empty()) {          // 递归的出口，对应栈为空
        return;
    }
    int bottom = getAndDelLastElem(stk);
    reverse(stk);
    stk.push(bottom);
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