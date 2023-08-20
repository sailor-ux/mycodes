#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 0~n-1, 如果缺失的是n-1, 应该返回n-1, 即nums数组的长度n, 实际返回pos的初值！
        // 所以pos的初值要为n！！！
        int n = nums.size(), l = 0, r = n - 1, pos = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid != nums[mid]) {
                pos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return pos;
    }
};
int main() {

    system("pause");
    return 0;
}