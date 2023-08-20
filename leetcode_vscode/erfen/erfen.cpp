#include <iostream>
#include <vector>
using namespace std;
// 二分查找：https://www.bilibili.com/video/BV1AP41137w7/?vd_source=3ea13c3621b7c400667eb80cb0354057
// 154题，三叶姐
int erfen01(vector<int>& nums, int val) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == val) {
            return mid;
        } else if (nums[mid] > val) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1; // 要找的值val如果在数组nums中存在，mid可以找到；如果不存在，退出while循环返回-1！！！
}
int erfen02(vector<int>& nums, int val) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = (left + right + 1) / 2; // mid右偏，摆脱死循环，此时保证了mid>=1，nums[mid-1]合法！
        if (nums[mid] > val) {
            right = mid - 1;
        } else {
            left = mid; // 警惕死循环！！！死循环的情况：r==l+1,并且走了else即left = mid, mid左偏！
        }
    }
    // return left;
    return nums[left] == val ? left : -1; // 要找的值val如果在数组nums中存在，l和r可以准确无误的找到；如果不存在，l和r可就找错了！！！
}
int main() {
    vector<int> nums{1, 3, 4, 8, 10, 19, 33};
    cout << erfen02(nums, 4);
    system("pause");
    return 0;
}