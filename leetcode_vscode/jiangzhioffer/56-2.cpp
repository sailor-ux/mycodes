#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // num������bitMask����
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0); // ȫ�����ְ�λ��ӵĽ��
        for (const int& num : nums) {
            int bitMask = 1;
            for (int i = 31; i >= 0; i--) {
                bits[i] += (num & bitMask) == 0 ? 0 : 1; // ϸ�ڱ��뵱Ȼ��
                if (i > 0) {                             // ���ѭ��32�Σ�����32λ�����bitMask���33λ���������
                    bitMask <<= 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i] % 3 == 1) {
                res += 1 << (31 - i);
            }
        }
        return res;
    }
    // num���ƣ�bitMask������ʼ��Ϊ1��ʼ����1��λ����
    // ���ַ�ʽ���ã�û����ô��Ҫע���ϸ�ڣ���
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0); // ȫ�����ְ�λ��ӵĽ��
        for (int num : nums) {
            for (int i = 31; i >= 0; i--) {
                bits[i] += num & 1;
                num >>= 1;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i] % 3 == 1) {
                res += 1 << (31 - i);
            }
        }
        return res;
    }
};
int main() {
    vector<int> nums{6, 1, 1, 1};
    Solution sol;
    cout << sol.singleNumber(nums);
    system("pause");
    return 0;
}