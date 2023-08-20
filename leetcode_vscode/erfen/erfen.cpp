#include <iostream>
#include <vector>
using namespace std;
// ���ֲ��ң�https://www.bilibili.com/video/BV1AP41137w7/?vd_source=3ea13c3621b7c400667eb80cb0354057
// 154�⣬��Ҷ��
int erfen01(vector<int>& nums, int val) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == val) {
            return mid;
        } else if (nums[mid] > val) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1; // Ҫ�ҵ�ֵval���������nums�д��ڣ�mid�����ҵ�����������ڣ��˳�whileѭ������-1������
}
int erfen02(vector<int>& nums, int val) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = (left + right + 1) / 2; // mid��ƫ��������ѭ������ʱ��֤��mid>=1��nums[mid-1]�Ϸ���
        if (nums[mid] > val) {
            right = mid - 1;
        } else {
            left = mid; // ������ѭ����������ѭ���������r==l+1,��������else��left = mid, mid��ƫ��
        }
    }
    // return left;
    return nums[left] == val ? left : -1; // Ҫ�ҵ�ֵval���������nums�д��ڣ�l��r����׼ȷ������ҵ�����������ڣ�l��r�ɾ��Ҵ��ˣ�����
}
int main() {
    vector<int> nums{1, 3, 4, 8, 10, 19, 33};
    cout << erfen02(nums, 4);
    system("pause");
    return 0;
}