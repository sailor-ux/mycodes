#include <iostream>
using namespace std;
//λ����ʵ�����������
//ԭ���������ľ���ϸ����ʵҲû��Ҫ֪��
// a+b = a+b�Ĳ��� = a�Ĳ�����b�Ĳ��밴λ���
class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        unsigned int carry = 0; //�޷��ŵ���������ֹ���
        do {
            sum = a ^ b;                        //������������൱�ڲ����ǽ�λ�����������
            carry = (unsigned int)(a & b) << 1; //��λ��Ϊ1����Щλ�������Ե�λ�Ľ�λ
            a = sum;
            b = carry;
        } while (b); //ֱ����λΪ0
        return sum;
    }
};
int main() {
    Solution sol;
    cout << sol.getSum(-10, 8);
    system("pause");
    return 0;
}