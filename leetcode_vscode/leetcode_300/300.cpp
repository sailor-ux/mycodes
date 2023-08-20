#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> d;
        d.push_back(-1);
        d.push_back(nums[0]);
        int len = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > d[len]) {
                d.push_back(nums[i]);
                len++;
            } else {
                int l = 1, r = len, pos = 0;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};
int main() {

    system("pause");
    return 0;
}