#include <iostream>
#include <queue>
using namespace std;
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> maxQ;
    priority_queue<int, vector<int>, less<int>> minQ;
    bool flag;
    MedianFinder() {
        flag = true;
    }

    void addNum(int num) {
        if (flag) { // 数据的总数目是偶数，新数据插入最小堆(小根堆)
            maxQ.push(num);
            minQ.push(maxQ.top());
            maxQ.pop();
        } else { // 数据的总数目是奇数，新数据插入最大堆(大根堆)
            minQ.push(num);
            maxQ.push(minQ.top());
            minQ.pop();
        }
        flag = !flag;
    }

    double findMedian() {
        if (flag) {
            return (maxQ.top() + minQ.top()) / 2.0;
        }
        return minQ.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main() {

    system("pause");
    return 0;
}