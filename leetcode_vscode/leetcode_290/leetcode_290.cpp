#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> mp(26);
        unordered_map<string, int> fmp;
        int begin = 0;
        for (const char& ch : pattern) {
            if (begin == s.length() + 1) {
                return false;
            }
            int i = begin;
            while (i < s.length() && s[i] != ' ') {
                i++;
            }
            string str = s.substr(begin, i - begin);
            if (mp[ch - 'a'].empty()) {
                mp[ch - 'a'] = str;
            } else if (mp[ch - 'a'] != str) {
                return false;
            }
            if (!fmp.count(str)) {
                fmp[str] = ch - 'a';
            } else if (fmp[str] != ch - 'a') {
                return false;
            }
            begin = i + 1;
        }
        return begin == s.length() + 1;
    }
};
int main() {
    string pattern = "aaa";
    string s = "aa aa aa aa";
    Solution sol;
    cout << sol.wordPattern(pattern, s);
    system("pause");
    return 0;
}