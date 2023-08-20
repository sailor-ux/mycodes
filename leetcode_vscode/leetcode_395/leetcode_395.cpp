#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //分治，需要二刷！
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
            if (cnt[i] > 0 && cnt[i] < k) { //满足条件用于分割的字符split可能存在多个，就找一个即可，其他的在后续的子串中会被找到！
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