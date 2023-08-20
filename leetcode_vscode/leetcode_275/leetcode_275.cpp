#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1, H = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (citations[mid] >= n - mid) {
                if (mid == 0 || citations[mid - 1] <= n - mid) {
                    H = n - mid;
                }
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return H;
    }
};
int main() {
    vector<int> citations{1};
    Solution sol;
    cout << sol.hIndex(citations);
    system("pause");
    return 0;
}
