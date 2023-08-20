#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // O(n*n)���͵ı�����ʱ�ⷨ��ö�����е����䡢�����
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size(), count = 0;
        for (int i = 0; i < n; i++) {
            long sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum >= lower && sum <= upper) {
                    count++;
                }
            }
        }
        return count;
    }
};
int main() {

    system("pause");
    return 0;
}