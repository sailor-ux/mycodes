#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //���Σ���Ҫ��ˢ��
    int longestSubstring(string s, int k) {
        return dfs(s, 0, s.length() - 1, k);
    }
    int dfs(const string& s, int l, int r, const int& k) {
        vector<int> cnt(26, 0);
        for (int i = l; i <= r; i++) {
            cnt[s[i] - 'a']++;
        }
        char split = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0 && cnt[i] < k) { //�����������ڷָ���ַ�split���ܴ��ڶ��������һ�����ɣ��������ں������Ӵ��лᱻ�ҵ���
                split = i + 'a';
                break;
            }
        }
        if (split == -1) {
            return r - l + 1;
        }
        int res = 0;
        int i = l;
        while (i <= r) {
            while (i <= r && s[i] == split) {
                i++;
            }
            if (i > r) {
                break;
            }
            int start = i;
            while (i <= r && s[i] != split) {
                i++;
            }
            res = max(res, dfs(s, start, i - 1, k));
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}