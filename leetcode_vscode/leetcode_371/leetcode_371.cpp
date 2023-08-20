#include <iostream>
using namespace std;
//位运算实现两个数求和
//原、反、补的具体细则其实也没必要知道
// a+b = a+b的补码 = a的补码与b的补码按位相加
class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        unsigned int carry = 0; //无符号的类型来防止溢出
        do {
            sum = a ^ b;                        //两个数的异或相当于不考虑进位的两个数相加
            carry = (unsigned int)(a & b) << 1; //进位，为1的那些位存在来自低位的进位
            a = sum;
            b = carry;
        } while (b); //直到进位为0
        return sum;
    }
};
int main() {
    Solution sol;
    cout << sol.getSum(-10, 8);
    system("pause");
    return 0;
}