#include <iostream>
#include <queue>
using namespace std;
/* 满足单调性的deque是单调队列！
与前一题类似，
前一题，严格单调递减，存下标
这一题，不严格单调递减，单调不增！直接存的是数！ */
// 两题都在记忆！！！！！
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
        if (q.empty()) { // d也行
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