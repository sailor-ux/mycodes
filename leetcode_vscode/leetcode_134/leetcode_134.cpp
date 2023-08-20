#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 暴力超时！！！ 又改进写出来了，还需要二刷！！！
    // 发现规律：如果从第x个站出发，最多只能到第y个站，到不了第y+1个站，
    // 则：从第x个站~~第y个站中的任意一个站出发，也到不了第y+1个站。
    // 注意：y一定在回到第x个站之前(y可能>x，也可能<x，也可能=x)
    // x<=y，[x, y]跳过；
    // x>y， [0, y]U[x, n-1]跳过，就是跳过所有站，所有站都不行，直接返回-1！
    /* int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int index = -1;
        for (int i = 0; i < gas.size(); i++) {
            if (i <= index) {
                continue;
            }
            int sum = gas[i];
            for (int j = 0; j < gas.size(); j++) {
                index = (i + j) % n;
                sum -= cost[index];
                if (sum < 0) { // i --> index 可以，i --> index + 1 不行；i <=> x， index <=> y
                    if (i <= index) {
                        break;
                    } else {
                        return -1;
                    }
                }
                index = (index + 1) % n;
                if (index == i) {
                    return i;
                }
                sum += gas[index];
            }
        }
        return -1; // 可有可无，为了编译通过，必须要有！
    } */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            int begin = i;
            int rest = 0;
            while (1) {
                rest += gas[i];
                if (rest < cost[i]) {
                    break;
                }
                rest -= cost[i];
                i = (i + 1) % n;
                if (i == begin) {
                    return begin;
                }
            }
            i = begin;
        }
        return -1;
    }
};
int main() {
    vector<int> gas{2, 3, 4};
    vector<int> cost{3, 4, 3};
    Solution sol;
    cout << sol.canCompleteCircuit(gas, cost);
    system("pause");
    return 0;
}