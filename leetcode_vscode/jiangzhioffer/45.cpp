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
            // return stoi(strXY) < stoi(strYX); // �ַ���ת��Ϊ���ͣ�����int���Ϳ��ܻ������
            return strXY < strYX; // ����Ҫ���ַ���ת��Ϊ���������Ƚϣ��ַ�������ֱ�ӱȽϣ�
        });
        for (const int& num : nums) {
            // res += to_string(num);
            res.append(to_string(num)); // Ч������һ����һ���ģ�
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