#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0;
        unordered_set<int> record;
        for (const int& num : nums) {
            record.insert(num);
        }
        for (const int& num : nums) {
            if (!record.count(num - 1)) {
                int temp = num + 1;
                while (record.count(temp)) {
                    temp++;
                }
                if (temp - num > maxlen) {
                    maxlen = temp - num;
                }
            }
        }
        return maxlen;
    }
};
int main() {
    vector<int> nums{100, 4, 200, 1, 3, 2};
    Solution sol;
    cout << sol.longestConsecutive(nums);
    system("pause");
    return 0;
}