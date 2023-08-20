#include <iostream>
#include <stack>
using namespace std;
// �õݹ鷴תջ�������������ݽṹ
int getAndDelLastElem(stack<int>& s);
void reverse(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    int i = getAndDelLastElem(s); // �õ�ջ�׵�Ԫ�أ���ɾ��ջ��Ԫ��
    reverse(s);
    s.push(i); // �ٽ�ջ��Ԫ�طŽ�ջ��
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