#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> nums{2, 1, 5, 6, 8, 4, 3};
    int a = 6;
    const int& b = a;
    auto it = upper_bound(nums.begin(), nums.end(), b);
    cout << (int)*it;
    system("pause");
    return 0;
}