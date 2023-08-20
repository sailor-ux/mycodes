#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // Ħ��ͶƱ�����ٷ���⣬���������⣡
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int element1 = 0, vote1 = 0;
        int element2 = 0, vote2 = 0;
        for (const int& num : nums) {
            if (vote1 > 0 && num == element1) { // if�ķ�֧�ϲ���������ܺϲ���
                vote1++;
            } else if (vote2 > 0 && num == element2) {
                vote2++;
            } else if (vote1 == 0) {
                element1 = num;
                vote1++;
            } else if (vote2 == 0) {
                element2 = num;
                vote2++;
            } else {
                vote1--;
                vote2--;
            }
        }
        int cnt1 = 0, cnt2 = 0; // vote1>0, ����֤element1���ִ�������1/3; ����vote1=0, element1���ִ����϶�û�г���1/3
        for (const int& num : nums) {
            if (vote1 > 0 && num == element1) {
                cnt1++;
            }
            if (vote2 > 0 && num == element2) {
                cnt2++;
            }
        }
        if (vote1 > 0 && cnt1 > nums.size() / 3) {
            res.push_back(element1);
        }
        if (vote2 > 0 && cnt2 > nums.size() / 3) {
            res.push_back(element2);
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}