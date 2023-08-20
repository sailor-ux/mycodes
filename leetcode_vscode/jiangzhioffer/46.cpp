#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int translateNum(int num) {
        string strNum = to_string(num);
        int count = 0;
        dfs(strNum, count, 0);
        return count;
    }
    void dfs(const string& strNum, int& count, int i) { // 题目意思不是很清楚，我的答案考虑的更多！！
        if (i == strNum.length()) {
            count++;
            return;
        }
        // dfs(strNum, count, i + 1);
        //  if (i < strNum.length() - 1 && stoi(strNum.substr(i, 2)) < 26) {
        //      dfs(strNum, count, i + 2);
        //  }
        //  if (i < strNum.length() - 2 && stoi(strNum.substr(i, 3)) < 26) {
        //      dfs(strNum, count, i + 3);
        //  }
        for (int len = 1; len <= strNum.length(); len++) { // len是截取的长度
            if (i < strNum.length() - len + 1 && stoi(strNum.substr(i, len)) < 26) {
                dfs(strNum, count, i + len);
            } else {
                // break;
                return;
            }
        }
    }
    void dfs(const string& strNum, int& count, int i) { // 根据题意的答案
        if (i == strNum.length()) {
            count++;
            return;
        }
        dfs(strNum, count, i + 1);
        if (strNum[i] != '0' && i < strNum.length() - 1 && stoi(strNum.substr(i, 2)) < 26) {
            dfs(strNum, count, i + 2);
        }
    }
};
int main() {
    Solution sol;
    cout << sol.translateNum(506);
    system("pause");
    return 0;
}