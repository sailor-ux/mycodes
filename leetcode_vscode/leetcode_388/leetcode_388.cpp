#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    /* string lengthLongestPath(string input) {
        int n = input.length();
        string str;
        unordered_map<int, string> mp;
        for (int i = 0; i < n;) {
            int level = 0;
            while (i < n && input[i] == '\t') {
                level++;
                i++;
            }
            bool isFile = false;
            int j = i;
            while (j < n && input[j] != '\n') {
                if (input[j] == '.') {
                    isFile = true;
                }
                j++;
            }
            if (level == 0) {
                mp[level] = input.substr(i, j - i);
            } else {
                mp[level] = mp[level - 1] + '/' + input.substr(i, j - i);
            }
            if (isFile && mp[level].length() > str.length()) {
                str = mp[level];
            }
            i = j + 1;
        }
        return str;
    } */
    /* int lengthLongestPath(string input) {
        int n = input.length(), maxLen = 0;
        unordered_map<int, string> mp;
        for (int i = 0; i < n;) {
            int level = 0;
            while (i < n && input[i] == '\t') {
                level++;
                i++;
            }
            bool isFile = false;
            int j = i;
            while (j < n && input[j] != '\n') {
                if (input[j] == '.') {
                    isFile = true;
                }
                j++;
            }
            if (level == 0) {
                mp[level] = input.substr(i, j - i);
            } else {
                mp[level] = mp[level - 1] + '/' + input.substr(i, j - i);
            }
            if (isFile) {
                maxLen = max(maxLen, (int)mp[level].length());
            }
            i = j + 1;
        }
        return maxLen;
    } */
    /* int lengthLongestPath(string input) {
        int n = input.length(), maxLen = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n;) {
            int level = 0;
            while (i < n && input[i] == '\t') {
                level++;
                i++;
            }
            bool isFile = false;
            int j = i;
            while (j < n && input[j] != '\n') {
                if (input[j] == '.') {
                    isFile = true;
                }
                j++;
            }
            if (level == 0) {
                mp[level] = j - i;
            } else {
                mp[level] = mp[level - 1] + j - i + 1;
            }
            if (isFile) {
                maxLen = max(maxLen, mp[level]);
            }
            i = j + 1;
        }
        return maxLen;
    } */
    //不用unordered_map，非要用vector！
    int lengthLongestPath(string input) {
        int n = input.length(), maxLen = 0;
        vector<int> lengths;
        for (int i = 0; i < n;) {
            int level = 0;
            while (i < n && input[i] == '\t') {
                level++;
                i++;
            }
            bool isFile = false;
            int j = i;
            while (j < n && input[j] != '\n') {
                if (input[j] == '.') {
                    isFile = true;
                }
                j++;
            }
            if (level == lengths.size()) {
                lengths.push_back(-1);
            }
            if (level == 0) {
                lengths[level] = j - i;
            } else {
                lengths[level] = lengths[level - 1] + j - i + 1;
            }
            if (isFile) {
                maxLen = max(maxLen, lengths[level]);
            }
            i = j + 1;
        }
        return maxLen;
    }
};
int main() {
    Solution sol;
    cout << sol.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext");
    system("pause");
    return 0;
}