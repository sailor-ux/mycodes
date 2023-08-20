#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // ���ζ��ֲ��ң��ڶ��λ��ڵ�һ�εĲ��ҽ��(��һ��target���ֵ�λ��)���в��ң��ڶ��������ͷ��ʼ�����ܿ�һ��
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int l = 0, r = nums.size() - 1, pos = -1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == target) {
                pos = mid;
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (pos == -1) {
            return {-1, -1};
        }
        res.push_back(pos); // pos�ǵ�һ��target���ֵ�λ��
        l = pos, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == target) { // һ����nums[mid]>=target
                pos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        res.push_back(pos);
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int l = 0, r = nums.size() - 1, pos = -1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                if (nums[mid] == target) {
                    pos = mid;
                }
                r = mid - 1;
            }
        }
        if (pos == -1) {
            return {-1, -1};
        }
        res.push_back(pos); // pos�ǵ�һ��target���ֵ�λ��
        l = pos, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == target) { // һ����nums[mid]>=target
                pos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        res.push_back(pos);
        return res;
    }
};
int main() {
    vector<int> nums{5, 7, 7, 8, 8, 8, 8, 10, 11};
    Solution sol;
    vector<int> vec = sol.searchRange(nums, 10);
    cout << vec[0] << ' ' << vec[1];
    system("pause");
    return 0;
}