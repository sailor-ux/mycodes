#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    // 优先队列，大根堆，堆
    // 此解法的优势：不修改输入数组，适合海量数据
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) {
            return {};
        }
        priority_queue<int> q;
        for (const int& num : arr) {
            if (q.size() < k) {
                q.push(num);
            } else {
                if (num < q.top()) {
                    q.pop();
                    q.push(num);
                }
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}