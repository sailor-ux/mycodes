#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (const int& num : nums) {
            if ((num & 1) == 0) {
                mp[num]++;
            }
        }
        int even = -1, cnt = 0;
        for (auto& p : mp) { // 遍历unordered_map的方法！！
            if (p.second > cnt || (p.second == cnt && p.first < even)) {
                even = p.first;
                cnt = p.second;
            }
        }
        return even;
    }
};
int main() {

    system("pause");
    return 0;
}