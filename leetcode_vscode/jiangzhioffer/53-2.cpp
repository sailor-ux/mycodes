#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 0~n-1, ���ȱʧ����n-1, Ӧ�÷���n-1, ��nums����ĳ���n, ʵ�ʷ���pos�ĳ�ֵ��
        // ����pos�ĳ�ֵҪΪn������
        int n = nums.size(), l = 0, r = n - 1, pos = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid != nums[mid]) {
                pos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return pos;
    }
};
int main() {

    system("pause");
    return 0;
}