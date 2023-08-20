#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
  public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }
        unordered_map<char, int> hashT;
        for (char ch : t) {
            hashT[ch]++;
        }
        int l = 0, r = t.length() - 1, begin = -1, minlen = s.length() + 1;
        unordered_map<char, int> hashTemp;
        for (int i = l; i <= r; i++) {
            hashTemp[s[i]]++;
        }
        bool flag = false;
        while (l <= s.length() - t.length()) {
            while (!isInclude(hashTemp, hashT)) {
                if (r == s.length() - 1) {
                    flag = true;
                    break;
                }
                r++;
                hashTemp[s[r]]++;
            }
            if (flag) {
                break;
            }
            while (isInclude(hashTemp, hashT)) {
                hashTemp[s[l]]--;
                l++;
            }
            if (r - l + 2 < minlen) {
                begin = l - 1;
                minlen = r - l + 2;
            }
        }
        if (begin == -1) {
            return "";
        }
        return s.substr(begin, minlen);
    }
    bool isInclude(const unordered_map<char, int>& hashTemp, unordered_map<char, int>& hashT) {
        for (unordered_map<char, int>::iterator it = hashT.begin(); it != hashT.end(); it++) {
            if (hashTemp.find(it->first) == hashTemp.end() || hashTemp.at(it->first) < it->second) {
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution sol;
    cout << sol.minWindow("ADOBECODEBANC", "ABC");
    system("pause");
    return 0;
}