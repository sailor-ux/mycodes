#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // ʢˮ��������һ����ĳһ�����ӵĸ߶�Ϊ�ߣ�����ö��ÿһ�����ӵĸ߶�
    // Ѱ�����(�ұ�)���(��Զ)һ�����ڵ��ڵ�
    // ����ջ�Ļ���Ӧ�����ҵ�һ��(���)�����Բ����ϵ���ջ��
    // ʱ�临�Ӷ�O(n*n)��Ч��̫�ͣ�����˫ָ�룡����
    int maxArea(vector<int>& height) {
        int n = height.size(), maxCapacity = 0;
        for (int i = 0; i < n; i++) {
            int l = 0, r = n - 1;
            while (height[l] < height[i]) {
                l++;
            }
            while (height[r] < height[i]) {
                r--;
            }
            maxCapacity = max(maxCapacity, (i - l) * height[i]);
            maxCapacity = max(maxCapacity, (r - i) * height[i]);
        }
        return maxCapacity;
    }
};
int main() {

    system("pause");
    return 0;
}