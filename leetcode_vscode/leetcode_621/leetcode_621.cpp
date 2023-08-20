#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 桶思想！！！
    int leastInterval(vector<char>& tasks, int n) {
        int numOfTask = tasks.size();
        vector<int> vec(26);
        for (const char& ch : tasks) {
            vec[ch - 'A']++;
        }
        sort(vec.begin(), vec.end());
        int numOfTong = vec[25];
        int cnt = 1; // 最后一桶的任务数，至少为 1
        for (int i = 24; i >= 0; i--) {
            if (vec[i] < numOfTong) {
                break;
            }
            cnt++;
        }
        return max(numOfTask, (numOfTong - 1) * (n + 1) + cnt);
    }
};
int main() {
    Solution sol;

    system("pause");
    return 0;
}