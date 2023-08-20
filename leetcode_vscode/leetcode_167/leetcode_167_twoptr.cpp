#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                return {l + 1, r + 1};
            } else if (numbers[l] + numbers[r] < target) {
                l++;
            } else {
                r--;
            }
        }
        return {-1, -1};
    }
};
int main() {
    vector<int> numbers{2, 7, 11, 15};
    Solution sol;
    vector<int> res = sol.twoSum(numbers, 22);
    for (int& x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}