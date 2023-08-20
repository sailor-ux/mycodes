#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
  public:
    //��1�ͷ�2�����ǿ�����ģ�����
    // i => ret[i]������һλ�������^�����䷽�����������ͬΪ0����ͬΪ1
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