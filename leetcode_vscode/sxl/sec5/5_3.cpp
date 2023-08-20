#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end()), st2;
        for (const int& num : nums2) {
            if (st1.count(num)) {
                st2.insert(num);
            }
        }
        return vector<int>(st2.begin(), st2.end());
    }
};
int main() {

    system("pause");
    return 0;
}