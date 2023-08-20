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
            d.pop_back(); // 双端队列d的队首是队列q中的最大值，d中元素降序排列，d中小于value的元素可以放心大胆的剔除！
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