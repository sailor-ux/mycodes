#include <iostream>
using namespace std;
class Solution {
public:
    int lastRemaining(int n, int m) {
        int x = 0;                    // x=f(1)
        for (int i = 1; i < n; i++) { // ѭ��n-1�Σ�����n-1�Σ�״̬ת��n-1��
            x = (x + m) % (i + 1);
        }
        return x;
    }
};
int main() {

    system("pause");
    return 0;
}