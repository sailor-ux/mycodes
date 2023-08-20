#include <bitset>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    // bitset<n> nλ0�������������Ϊn��ÿ��Ԫ���� 0/1 (true/false) ������
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int n = s.length();
        unordered_map<char, int> hashMap{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        bitset<1 << 20> bs1, bs2;
        int val = 0, mask = (1 << 20) - 1;
        for (int i = 0; i < 10; i++) {
            val = val << 2 | hashMap[s[i]];
        }
        bs1.set(val);
        for (int i = 10; i < n; i++) {
            val = ((val << 2) & mask) | hashMap[s[i]];
            if (bs2.test(val)) { // val��Ӧ�����ַ������������(�������ڵĻ������ٳ���������)���Ѿ����ֹ������ˣ��Ѿ����ջ�������res���ˣ��������ǵ����Ρ����Ĵ�����....
                continue;
            }
            if (bs1.test(val)) {
                bs2.set(val);
                res.push_back(s.substr(i - 9, 10));
                continue;
            }
            bs1.set(val);
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}