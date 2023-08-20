#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // ����+˫ָ��
    vector<vector<int>> threeSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] == target) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    do {
                        l++;
                    } while (l < r && nums[l] == nums[l - 1]);
                    do {
                        r--;
                    } while (l < r && nums[r] == nums[r + 1]);
                } else if (nums[i] + nums[l] + nums[r] > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
    // ������֮������
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), minDistance = INT_MAX, res;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) {
                    return target;
                } else if (sum > target) {
                    if (sum - target < minDistance) {
                        res = sum;
                        minDistance = sum - target;
                    }
                    r--;
                } else {
                    if (target - sum < minDistance) {
                        res = sum;
                        minDistance = target - sum;
                    }
                    l++;
                }
            }
        }
        return res;
    }
    // ������֮�����ƣ����ǿ�����Ԫ��֮�Ϳ��ܳ���int���͵ı�ʾ��Χ�������������
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) { // j==i+1��������ǲ���continue�ģ�
                    continue;
                }
                int l = j + 1, r = n - 1;
                while (l < r) {
                    if ((long)nums[i] + (long)nums[j] + (long)nums[l] + (long)nums[r] == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        do {
                            l++;
                        } while (l < r && nums[l] == nums[l - 1]);
                        do {
                            r--;
                        } while (l < r && nums[r] == nums[r + 1]);
                    } else if ((long)nums[i] + (long)nums[j] + (long)nums[l] + (long)nums[r] > target) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};
int main() {

    system("pause");
    return 0;
}