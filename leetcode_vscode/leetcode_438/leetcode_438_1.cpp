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
        int diff = 0; // count中0的个数，若全为0，则：对于所有26个字母而言，滑动窗口包含的数量和字符串p包含的数量都相等，此时滑动窗口是p的异位词
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) {
                diff++;
            }
        }
        if (diff == 26) {
            ans.push_back(0);
        }
        for (int i = pLen; i < sLen; i++) {      // 滑动窗口丢弃s[i-pLen],添加s[i],考虑对diff的值会产生影响的情况
            if (count[s[i - pLen] - 'a'] == 1) { // 对于字母s[i-pLen]，本来窗口比p多1个，数量不同=>相同
                diff++;
            } else if (count[s[i - pLen] - 'a'] == 0) { // 数量相同=>不同，窗口比p少一个
                diff--;
            }
            count[s[i - pLen] - 'a']--;
            if (count[s[i] - 'a'] == -1) { // 对于字母s[i]，本来窗口比p少1个，数量不同=>相同
                diff++;
            } else if (count[s[i] - 'a'] == 0) { // 数量相同=>不同，窗口比p多一个
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