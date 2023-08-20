#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) { // �ַ�����ֻ����a~z���ַ�
        int n = s.length(), maxLen = 0;
        vector<bool> seen(26, false);
        int l = 0, r = 0; // ��������[l, r), ��ʼʱ������Ϊ��
        while (r < n) {
            while (r < n && !seen[s[r] - 'a']) {
                seen[s[r] - 'a'] = true;
                r++;
            }
            maxLen = max(maxLen, r - l);
            seen[s[l] - 'a'] = false;
            l++;
        }
        return maxLen;
    }
    int lengthOfLongestSubstring(string s) { // �ַ������԰��������ַ�
        int n = s.length(), maxLen = 0;
        unordered_set<char> st;
        int l = 0, r = 0; // ��������[l, r), ��ʼʱ������Ϊ��
        while (r < n) {
            while (r < n && !st.count(s[r])) {
                st.insert(s[r]);
                r++;
            }
            maxLen = max(maxLen, r - l);
            st.erase(s[l]);
            l++;
        }
        return maxLen;
    }
};
int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("arabcacfr");
    system("pause");
    return 0;
}