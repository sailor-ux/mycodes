#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int>& nums;
    vector<int> original;
    int n;
    Solution(vector<int>& nums) : nums(nums), original(nums) {
        n = nums.size();
    }

    vector<int> reset() {
        // copy(original.begin(), original.end(), nums.begin());
        nums = original;
        return nums;
    }

    vector<int> shuffle() {
        for (int i = 0; i < n; i++) {
            swap(nums[i], nums[rand() % (n - i) + i]); //ϴ���㷨��i��[i,n-1]���䵱�е�һ�����λ��������
        }
        return nums;
    }
};
int main() {

    system("pause");
    return 0;
}