#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 摩尔投票法，官方题解，代码更好理解！
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int element1 = 0, vote1 = 0;
        int element2 = 0, vote2 = 0;
        for (const int& num : nums) {
            if (vote1 > 0 && num == element1) { // if的分支合并会出错，不能合并！
                vote1++;
            } else if (vote2 > 0 && num == element2) {
                vote2++;
            } else if (vote1 == 0) {
                element1 = num;
                vote1++;
            } else if (vote2 == 0) {
                element2 = num;
                vote2++;
            } else {
                vote1--;
                vote2--;
            }
        }
        int cnt1 = 0, cnt2 = 0; // vote1>0, 不保证element1出现次数超过1/3; 但是vote1=0, element1出现次数肯定没有超过1/3
        for (const int& num : nums) {
            if (vote1 > 0 && num == element1) {
                cnt1++;
            }
            if (vote2 > 0 && num == element2) {
                cnt2++;
            }
        }
        if (vote1 > 0 && cnt1 > nums.size() / 3) {
            res.push_back(element1);
        }
        if (vote2 > 0 && cnt2 > nums.size() / 3) {
            res.push_back(element2);
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}