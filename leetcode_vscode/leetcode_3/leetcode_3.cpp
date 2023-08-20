#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    // ��������(���ظ��ַ����Ӵ�)�ķ�Χ��[l, r), �������ַ��ڼ���st��
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l = 0, r = 0, n = s.length(), maxLen = 0;
        while (r < n) {
            if (st.count(s[r])) {
                // maxLen = max(maxLen, r - l);
                st.erase(s[l++]);
            } else {
                st.insert(s[r]);
                r++;
                maxLen = max(maxLen, r - l);
            }
        }
        return maxLen;
    }
};
int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("bbbbba");
    system("pause");
    return 0;
}