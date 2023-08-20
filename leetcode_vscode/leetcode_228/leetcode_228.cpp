#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0;
        while (i < nums.size()) {
            int j = i + 1;
            while (j < nums.size() && nums[j - 1] + 1 == nums[j]) {
                j++;
            }
            if (i == j - 1) {
                res.push_back(to_string(nums[i]));
            } else {
                res.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
            }
            i = j;
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}