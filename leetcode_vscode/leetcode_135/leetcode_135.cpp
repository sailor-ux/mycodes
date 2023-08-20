#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0;
        int n = ratings.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i - 1] < ratings[i]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            if (ratings[i - 1] > ratings[i]) {
                right[i - 1] = right[i] + 1;
            }
            sum += max(left[i], right[i]);
        }
        return sum += max(left[0], right[0]);
    }
};
int main() {

    system("pause");
    return 0;
}