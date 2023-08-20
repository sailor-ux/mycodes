#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int resXor = 0; // ȫ���������ֻ����һ�ε����ֵ����a^b
        for (const int& num : nums) {
            resXor ^= num;
        }
        int index = findFirstBitIs1(resXor); // resXor�ĵ�indexλΪ1�����ÿһλ��Ϊ0
        int res1 = 0, res2 = 0;
        for (const int& num : nums) {
            if ((num >> index) & 1) { // num�ĵ�indexλΪ1
                res1 ^= num;
            } else { // num�ĵ�indexλΪ0
                res2 ^= num;
            }
        }
        return {res1, res2};
    }
    int findFirstBitIs1(int num) {
        int indexBit = 0;
        while ((num & 1) == 0) { // �ж�num�ĵ�indexBitλ
            indexBit++;
            num = num >> 1;
        }
        return indexBit; // num�ĵ�indexBitλΪ1�����ÿһλ��Ϊ0
    }
};
int main() {
    vector<int> nums{2, 4, 3, 6, 3, 2, 5, 5};
    Solution sol;
    vector<int> res = sol.singleNumbers(nums);
    cout << res[0] << ' ' << res[1];
    system("pause");
    return 0;
}