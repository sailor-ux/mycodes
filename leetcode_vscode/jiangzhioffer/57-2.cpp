#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // ���к�=targetʱ������ͨ������big��Ѱ���µĿ��е����У�����small���У���������
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int l = 1, r = 2, sum = 3;
        while (l <= target / 2) {
            if (sum > target) {
                sum -= l;
                l++;
            } else {
                if (sum == target) {
                    vector<int> vec;
                    for (int i = l; i <= r; i++) {
                        vec.push_back(i);
                    }
                    res.push_back(vec);
                }
                r++;
                sum += r;
            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> res = sol.findContinuousSequence(15);
    for (const vector<int>& vec : res) {
        for (const int& x : vec) {
            cout << x << ' ';
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}