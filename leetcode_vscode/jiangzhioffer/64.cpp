#include <iostream>
using namespace std;
class Solution {
public:
    int sumNums(int n) {
        return n == 1 ? 1 : n + sumNums(n - 1);
    }
    int sumNums(int n) {
        return n == 0 ? 0 : n + sumNums(n - 1);
    }
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};
int main() {

    system("pause");
    return 0;
}