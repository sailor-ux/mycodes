#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size() - 1; i++) {
            int low = i + 1, high = numbers.size() - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (numbers[mid] + numbers[i] == target) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] + numbers[i] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return {};
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