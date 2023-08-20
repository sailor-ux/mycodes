#include <iostream>
using namespace std;
class Solution {
public:
    int add(int a, int b) {
        if (b == 0) {
            return a;
        }
        int n = a ^ b;
        int c = (unsigned int)(a & b) << 1; // C++�и�����֧������λ
        return add(n, c);
    }
    int add(int a, int b) {
        while (b != 0) {
            int c = (unsigned int)(a & b) << 1; // C++�и�����֧������λ
            a = a ^ b;
            b = c;
        }
        return a;
    }
};
int main() {

    system("pause");
    return 0;
}