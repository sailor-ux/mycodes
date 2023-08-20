#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s1, string s2) { // s1�ı�����s2��ģʽ��
        int m = s1.length(), n = s2.length();
        if (m < n) {
            return false;
        }
        vector<int> next = getNextArr(s2);
        int j = -1;
        for (int i = 0; i < m; i++) {
            while (j >= 0 && s1[i] != s2[j + 1]) {
                j = next[j];
            }
            if (s1[i] == s2[j + 1]) {
                j++;
            }
            if (j == n - 1) {
                return true;
            }
        }
        return false;
    }
    int isMatch2(string s1, string s2) { // s1�ı�����s2��ģʽ��
        int m = s1.length(), n = s2.length();
        if (m < n) {
            return -1;
        }
        vector<int> next = getNextArr(s2);
        int j = -1;
        for (int i = 0; i < m; i++) {
            while (j >= 0 && s1[i] != s2[j + 1]) {
                j = next[j];
            }
            if (s1[i] == s2[j + 1]) {
                j++;
            }
            if (j == n - 1) {
                return i - n + 1;
            }
            // �汾�ĵݽ���
            /* while (s1[i] != s2[j + 1]) {
                j = next[j];
            }
            j++; */
            /* while (j >= 0 && s1[i] != s2[j + 1]) {
                j = next[j];
            }
            if (s1[i] == s2[j + 1]) {
                j++;
            } */
            /* while (j >= 0 && s1[i] != s2[j + 1]) {
                j = next[j];
            }
            if (s1[i] == s2[j + 1]) {
                j++;
            }
            if (j == n - 1) {
                return i + 1 - n;
            } */
        }
        return -1;
    }
    vector<int> getNextArr(const string& s) {
        int n = s.length();
        vector<int> next(n);
        int j = -1;
        next[0] = j;
        for (int i = 1; i < n; i++) {
            while (j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[i] == s[j + 1]) {
                j++;
                // next[i] = j;
            }
            next[i] = j;
            // �汾�ĵݽ���
            /* while (s[i] != s[j + 1]) {
                j = next[j];
            }
            j++;
            next[i] = j; */
            /* // j<0(��j=-1)��s[i] != s[j + 1]ʱ����һ�����ɶҲû��������Ӧ��Ҫ��next[i]��ֵ�Ŷԣ��Ҹ�ֵΪ-1��j����
            // ����next[i] = j�������棡����
            while (j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[i] == s[j + 1]) {
                j++;
                next[i] = j;
            } */
        }
        return next;
    }
};
int main() {
    string haystack = "aaabaaabbbabaa", needle = "babb";
    Solution sol;
    cout << sol.isMatch2(haystack, needle);
    system("pause");
    return 0;
}