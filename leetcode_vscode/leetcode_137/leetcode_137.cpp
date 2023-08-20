#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
  public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int total = 0;
            for (const int& num : nums) {
                total += (num >> i) & 1; // num的第i个二进制位
            }
            if (total % 3) { // total % 3(0 或 1)是答案的第i个二进制位
                res += (1 << i);
            }
        }
        return res;
    }
};
int main() {
    vector<int> arr{0, 1, 0, 1, 0, 1, 99};
    Solution sol;
    cout << sol.singleNumber(arr);
    system("pause");
    return 0;
}

// int singleNumber(vector<int>& nums) {
//     map<int, int> hash;
//     for (int num : nums) {
//         hash[num]++;
//     }
//     for (auto [key, value] : hash) {
//         if (value == 1) {
//             return key;
//         }
//     }
// }