#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> d;
        int len = 1;
        d.push_back(-1);
        d.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (d[len] < nums[i]) {
                len++;
                d.push_back(nums[i]);
            } else {
                int left = 1, right = len, pos = 0; // pos�����Ϊ��ʼֵ0,˵��Ŀǰ����d������Ԫ��ȫ������>=nums[i],�Ҳ���<nums[i]��,nums[i]<=d[1],d[1]����Ϊnums[i]!
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};
int main() {

    system("pause");
    return 0;
}