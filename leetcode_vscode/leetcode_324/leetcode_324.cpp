#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 3 3 2 2 1 1, Òª½µÐò£¡£¡£¡
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int& a, int& b) { return a > b; });
        int n = nums.size();
        int m = n / 2;
        vector<int> temp;
        for (int i = 0; i < m; i++) {
            temp.push_back(nums[i + m]);
            temp.push_back(nums[i]);
        }
        if (n % 2 == 1) {
            temp.push_back(nums[n - 1]);
        }
        nums = temp;
    }
};
int main() {

    system("pause");
    return 0;
}