#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
  public:
    //法1和法2，都是靠记忆的！！！
    // i => ret[i]，右移一位，再异或^（记忆方法），异或：相同为0，不同为1
    vector<int> grayCode(int n) {
        vector<int> ret(1 << n); // 1 << n == pow(2,n)
        for (int i = 0; i < ret.size(); i++) {
            ret[i] = (i >> 1) ^ i;
        }
        return ret;
    }
};
int main() {
    Solution sol;
    vector<int> res = sol.grayCode(2);
    for (const int& x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}