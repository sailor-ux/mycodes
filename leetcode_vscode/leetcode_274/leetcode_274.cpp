#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n - i && (i == 0 || citations[i - 1] <= n - i)) {
                return n - i;
            }
        }
        return 0;
    }
};
int main() {
    vector<int> citations{1};
    Solution sol;
    cout << sol.hIndex(citations);
    system("pause");
    return 0;
}
