#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x = min({a, b, c});
        int z = max({a, b, c});
        int y = a + b + c - x - z;
        if (y - x == 1 && z - y == 1) { // 三颗石子已经连续
            return {0, 0};
        }
        if (y - x <= 2 || z - y <= 2) { // 三颗石子不连续且其中有两颗石子的间隔小于等于2
            return {1, z - x - 2};
        }
        return {2, z - x - 2}; // 三颗石子两两之间间隔大于2
    }
};
int main() {

    system("pause");
    return 0;
}