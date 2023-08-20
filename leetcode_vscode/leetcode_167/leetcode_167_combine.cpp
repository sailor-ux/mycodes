#include <iostream>
#include <vector>
using namespace std;
// 双指针里面加入二分法！！！
// 实际提交来看也没快多少！
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (numbers[l] + numbers[mid] > target) { // 小范围，先处理掉！
                r = mid - 1;
            } else if (numbers[mid] + numbers[r] < target) {
                l = mid + 1;
            } else if (numbers[l] + numbers[r] > target) { // 大范围
                r--;
            } else if (numbers[l] + numbers[r] < target) {
                l++;
            } else {
                return {l + 1, r + 1};
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