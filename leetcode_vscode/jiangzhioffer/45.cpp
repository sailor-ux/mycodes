#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string minNumber(vector<int>& nums) {
        string res = "";
        sort(nums.begin(), nums.end(), [](const int& x, const int& y) {
            string strX = to_string(x), strY = to_string(y);
            string strXY = strX + strY, strYX = strY + strX;
            // return stoi(strXY) < stoi(strYX); // 字符串转换为整型，对于int类型可能会溢出！
            return strXY < strYX; // 不需要把字符串转换为整型再做比较，字符串可以直接比较！
        });
        for (const int& num : nums) {
            // res += to_string(num);
            res.append(to_string(num)); // 效果跟上一行是一样的！
        }
        return res;
    }
};
int main() {
    vector<int> nums{999999998, 999999997, 999999999};
    Solution sol;
    cout << sol.minNumber(nums);
    system("pause");
    return 0;
}