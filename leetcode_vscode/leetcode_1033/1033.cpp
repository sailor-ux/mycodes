#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x = min({a, b, c});
        int z = max({a, b, c});
        int y = a + b + c - x - z;
        if (y - x == 1 && z - y == 1) { // ����ʯ���Ѿ�����
            return {0, 0};
        }
        if (y - x <= 2 || z - y <= 2) { // ����ʯ�Ӳ�����������������ʯ�ӵļ��С�ڵ���2
            return {1, z - x - 2};
        }
        return {2, z - x - 2}; // ����ʯ������֮��������2
    }
};
int main() {

    system("pause");
    return 0;
}