#include <deque>
#include <iostream>
#include <queue>
using namespace std;
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
            d.pop_back(); // ˫�˶���d�Ķ����Ƕ���q�е����ֵ��d��Ԫ�ؽ������У�d��С��value��Ԫ�ؿ��Է��Ĵ󵨵��޳���
        }
        d.push_back(value);
        q.push(value);
    }

    int pop_front() {
        if (d.empty()) {
            return -1;
        }
        int ans = q.front();
        if (ans == d.front()) {
            d.pop_front();
        }
        q.pop();
        return ans;
    }
};
int main() {

    system("pause");
    return 0;
}