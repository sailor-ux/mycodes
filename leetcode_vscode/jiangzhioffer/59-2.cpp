#include <iostream>
#include <queue>
using namespace std;
/* ���㵥���Ե�deque�ǵ������У�
��ǰһ�����ƣ�
ǰһ�⣬�ϸ񵥵��ݼ������±�
��һ�⣬���ϸ񵥵��ݼ�������������ֱ�Ӵ�������� */
// ���ⶼ�ڼ��䣡��������
class MaxQueue {
public:
    queue<int> q;
    deque<int> d;
    MaxQueue() {
    }

    int max_value() {
        return d.empty() ? -1 : d.front();
    }

    void push_back(int value) {
        while (!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }

    int pop_front() {
        if (q.empty()) { // dҲ��
            return -1;
        }
        int ans = q.front();
        q.pop();
        if (d.front() == ans) {
            d.pop_front();
        }
        return ans;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
int main() {

    system("pause");
    return 0;
}