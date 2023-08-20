#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
  public:
    int singleNumber(vector<int>& nums) {
        int single = 0;
        for (const int& num : nums) {
            single ^= num;
        }
        return single;
    }
};
int main() {
    vector<int> arr{4, 1, 2, 1, 2, 4, 5, 6, 6};
    Solution sol;
    cout << sol.singleNumber(arr);
    system("pause");
    return 0;
}

// int singleNumber(vector<int>& nums) {
//     unordered_set<int> st;
//     for (const int& num : nums) {
//         if (st.count(num)) {
//             st.erase(num);
//         } else {
//             st.insert(num);
//         }
//     }
//     return *(st.begin());
// }