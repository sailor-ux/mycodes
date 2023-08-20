#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int sLen = s.size(), pLen = p.size();
        if (sLen < pLen) {
            return ans;
        }
        vector<int> count(26, 0);
        for (int i = 0; i < pLen; i++) {
            count[s[i] - 'a']++;
            count[p[i] - 'a']--;
        }
        int diff = 0; // count��0�ĸ�������ȫΪ0���򣺶�������26����ĸ���ԣ��������ڰ������������ַ���p��������������ȣ���ʱ����������p����λ��
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) {
                diff++;
            }
        }
        if (diff == 26) {
            ans.push_back(0);
        }
        for (int i = pLen; i < sLen; i++) {      // �������ڶ���s[i-pLen],���s[i],���Ƕ�diff��ֵ�����Ӱ������
            if (count[s[i - pLen] - 'a'] == 1) { // ������ĸs[i-pLen]���������ڱ�p��1����������ͬ=>��ͬ
                diff++;
            } else if (count[s[i - pLen] - 'a'] == 0) { // ������ͬ=>��ͬ�����ڱ�p��һ��
                diff--;
            }
            count[s[i - pLen] - 'a']--;
            if (count[s[i] - 'a'] == -1) { // ������ĸs[i]���������ڱ�p��1����������ͬ=>��ͬ
                diff++;
            } else if (count[s[i] - 'a'] == 0) { // ������ͬ=>��ͬ�����ڱ�p��һ��
                diff--;
            }
            count[s[i] - 'a']++;
            if (diff == 26) {
                ans.push_back(i - pLen + 1);
            }
        }
        return ans;
    }
};
int main() {

    system("pause");
    return 0;
}