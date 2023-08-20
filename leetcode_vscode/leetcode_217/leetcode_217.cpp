#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};
int main() {

    system("pause");
    return 0;
}

// unordered_set<int> st;
// for (const int& num : nums) {
//     if (st.find(num) != st.end()) {
//         return true;
//     }
//     st.insert(num);
// }
// return false;