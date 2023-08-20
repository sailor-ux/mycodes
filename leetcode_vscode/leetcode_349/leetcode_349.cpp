#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res_st;
        unordered_set<int> nums1_st(nums1.begin(), nums1.end()); // vector<int>תunordered_set<int>
        for (const int& num : nums2) {
            if (nums1_st.count(num) && !res_st.count(num)) {
                res_st.insert(num);
            }
        }
        return vector<int>(res_st.begin(), res_st.end()); // unordered_set<int>תvector<int>
    }
};
int main() {

    system("pause");
    return 0;
}