#include <iostream>
#include <stack>
using namespace std;
// �ݹ�����һ����ջ�ڽ�ʣջ��Ԫ��һ��Ԫ�أ��൱�ڵݹ�����һ����ǰ��һλ���ݹ�����һ���������һ��
// ��ΪҪ��ջ��Ԫ��һ·����ȥһ·����return�����Եݹ�����һ�����ջ�ڽ�ʣջ��Ԫ��
// ���������ͨ�ĵݹ飬�ݹ�����һ����ջΪ�գ���ôջ���ջ���ָ�����ԭ�������ӣ��޷�����ɾ��ջ��Ԫ�أ����Һ������޷�ӵ�з���ֵ�����������û�з���ֵ����ôҲ���޷���ջ��Ԫ��һ·����ȥ
// �ݵĹ��̣����ϳ�ջ����Ĺ��̣����ղŵ�ջ��Ԫ������ջ�����ҽ�ջ��Ԫ��һ·����ȥ
int getAndDelLastElem(stack<int>& stk) { // ��ȡ��ɾ��ջ��Ԫ��
    int val = stk.top();
    stk.pop();
    if (stk.empty()) { // �ݹ�ĳ��ڣ���Ӧջ�ڽ�ʣ��һ��ջ��Ԫ��
        return val;
    }
    int bottom = getAndDelLastElem(stk);
    stk.push(val);
    return bottom;
}
void reverse(stack<int>& stk) { // ��������ͨ������ĵݹ顣�ݹ�����һ�㣬����ջΪ��
    if (stk.empty()) {          // �ݹ�ĳ��ڣ���ӦջΪ��
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