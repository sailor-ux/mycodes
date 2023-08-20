#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        if (n == 0) {
            return {};
        }
        vector<int> c(n), d(n), b(n);
        c[0] = 1, d[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            c[i] = c[i - 1] * a[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            d[i] = d[i + 1] * a[i + 1];
        }
        for (int i = 0; i < n; i++) {
            b[i] = c[i] * d[i];
        }
        return b;
    }
};
int main() {

    system("pause");
    return 0;
}