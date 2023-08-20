#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // ������ʱ������ �ָĽ�д�����ˣ�����Ҫ��ˢ������
    // ���ֹ��ɣ�����ӵ�x��վ���������ֻ�ܵ���y��վ�������˵�y+1��վ��
    // �򣺴ӵ�x��վ~~��y��վ�е�����һ��վ������Ҳ�����˵�y+1��վ��
    // ע�⣺yһ���ڻص���x��վ֮ǰ(y����>x��Ҳ����<x��Ҳ����=x)
    // x<=y��[x, y]������
    // x>y�� [0, y]U[x, n-1]������������������վ������վ�����У�ֱ�ӷ���-1��
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
                if (sum < 0) { // i --> index ���ԣ�i --> index + 1 ���У�i <=> x�� index <=> y
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
        return -1; // ���п��ޣ�Ϊ�˱���ͨ��������Ҫ�У�
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