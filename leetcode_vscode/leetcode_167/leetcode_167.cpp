#include <iostream>
#include <vector>
using namespace std;
// ·ÑÊ±¼ä£¡
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size() - 1; i++) {
            // if (numbers[i] + numbers[i + 1] > target) {
            //     return {};
            // }
            if (numbers[i] + numbers.back() < target) {
                continue;
            }
            for (int j = i + 1; j < numbers.size(); j++) {
                if (numbers[i] + numbers[j] == target) {
                    return {i + 1, j + 1};
                }
            }
        }
        return {};
    }
};
int main() {
    vector<int> numbers{2, 7, 11, 15};
    Solution sol;
    vector<int> res = sol.twoSum(numbers, 9);
    for (int& x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}