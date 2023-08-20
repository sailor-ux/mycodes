#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    // 如何实现除法的计算，整数部分直接整除就可以获得，但如何确定小数部分的每一位，还要考虑可能出现循环小数(循环节)
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        string str;
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
            str += '-';
        }
        long numeratorLong = numerator;
        long denominatorLong = denominator;
        numeratorLong = abs(numeratorLong);
        denominatorLong = abs(denominatorLong);
        bool flag = true, isExistCycle = false;
        unordered_map<long, int> hashMap;
        int idx = 1;
        while (numeratorLong) {
            if (hashMap.count(numeratorLong)) {
                isExistCycle = true;
                idx = hashMap[numeratorLong]; // 第idx位小数至最后存在循环
                break;
            }
            if (!flag) {
                hashMap[numeratorLong] = idx++;
            }
            long x = numeratorLong / denominatorLong;
            str += to_string(x);
            if (flag) {
                str += ".";
                flag = false;
            }
            numeratorLong -= x * denominatorLong; // 余数
            numeratorLong *= 10;
        }
        if (!isExistCycle) {
            if (str.back() == '.') {
                str.erase(str.end() - 1);
            }
            return str;
        }
        int i = 0;
        for (; i < str.length(); i++) {
            if (str[i] == '.') {
                break;
            }
        }
        str.insert(str.begin() + i + idx, '(');
        str += ')';
        return str;
    }
};
int main() {
    Solution sol;
    cout << sol.fractionToDecimal(-2147483648, 1);
    system("pause");
    return 0;
}