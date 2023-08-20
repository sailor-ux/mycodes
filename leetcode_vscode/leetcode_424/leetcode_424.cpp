#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int l = 0, r = 0, maxCnt = 0, n = s.length(), len = 0;
        while (r < n) {
            cnt[s[r] - 'A']++;
            maxCnt = max(maxCnt, cnt[s[r] - 'A']);
            if (r - l + 1 - maxCnt > k) {
                cnt[s[l] - 'A']--;
                l++;
            }
            len = max(len, r - l + 1);
            r++;
        }
        return len;
    }
};
int main() {

    system("pause");
    return 0;
}