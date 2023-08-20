#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
    int bulbSwitch(int n) {
        // vector<int> bulbs(n, 1);
        // for (int i = 2; i <= n; i++) {
        //     for (int j = i - 1; j < n; j += i) {
        //         bulbs[j] = !bulbs[j];
        //     }
        // }
        // return accumulate(bulbs.begin(), bulbs.end(), 0);
        return (int)sqrt(n);
    }
};
int main() {

    system("pause");
    return 0;
}