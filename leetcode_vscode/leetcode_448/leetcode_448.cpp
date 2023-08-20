#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int num : nums) {
            // while (num > n) {
            //     num -= n;
            // }
            // nums[num - 1] += n;
            nums[(num - 1) % n] += n; // ”–µ„«…√Ó£°£°£°
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}