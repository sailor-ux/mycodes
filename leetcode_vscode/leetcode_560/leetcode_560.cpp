#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int pre = 0, count = 0;
        mp[0] = 1; // ����
        for (const int& num : nums) {
            pre += num;
            if (mp.count(pre - k)) {
                count += mp[pre - k];
            }
            mp[pre]++; // �÷���������ں���
        }
        return count;
    }
};
int main() {

    system("pause");
    return 0;
}