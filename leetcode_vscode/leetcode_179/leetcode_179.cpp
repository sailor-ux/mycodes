#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int& x, const int& y) {
            long sx = 10, sy = 10;
            while (sx <= x) {
                sx *= 10;
            }
            while (sy <= y) {
                sy *= 10;
            }
            return sy * x + y > sx * y + x;
        });
        if (nums[0] == 0) { // nums中全部为0
            return "0";
        }
        string str;
        for (const int& num : nums) {
            str += to_string(num);
        }
        return str;
    }
};
int main() {
    vector<int> nums{3, 30, 31, 5, 9};
    Solution sol;
    cout << sol.largestNumber(nums);
    system("pause");
    return 0;
}