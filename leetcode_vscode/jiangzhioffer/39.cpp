#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (cnt == 0) {
                val = nums[i];
                cnt = 1;
                continue;
            }
            if (nums[i] == val) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return val;
    }
};
int main() {

    system("pause");
    return 0;
}