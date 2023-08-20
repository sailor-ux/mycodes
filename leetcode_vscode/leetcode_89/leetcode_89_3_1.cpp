#include <cmath>
#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
  public:
    // 回溯法，暴力超时，写着玩，复习！！！（只找一种结果，找到就立刻往回结束）
    vector<int> grayCode(int n) {
        vector<int> res;
        unordered_set<int> record;
        bool flag = true;
        dfs(res, record, n, 0, flag);
        return res;
    }
    void dfs(vector<int>& res, unordered_set<int>& record, int& n, int index, bool& flag) {
        if (!flag) {
            return;
        }
        if (index == pow(2, n)) {
            if (isMatch(res[0], res.back())) {
                flag = false;
            }
            return;
        }
        for (int i = 0; i < pow(2, n); i++) {
            if (record.find(i) == record.end() && (res.empty() || isMatch(i, res.back()))) {
                if (!res.empty() || !i) {
                    res.push_back(i);
                    record.insert(i);
                    dfs(res, record, n, index + 1, flag);
                    if (flag) {
                        res.pop_back();
                        record.erase(i);
                    }
                }
            }
        }
    }
    bool isMatch(int& x, int& y) {
        string xBina = intToBina(x);
        string yBina = intToBina(y);
        string longStr = xBina.length() > yBina.length() ? xBina : yBina;
        string shortStr = xBina.length() > yBina.length() ? yBina : xBina;
        int longStrLen = longStr.length();
        int sub = longStrLen - shortStr.length();
        int sum = 0;
        for (int i = 0; i < longStrLen; i++) {
            if (i < sub && longStr[i] == '1') {
                if (++sum == 2) {
                    return false;
                }
            }
            if (i >= sub && longStr[i] != shortStr[i - sub]) {
                if (++sum == 2) {
                    return false;
                }
            }
        }
        return true;
    }
    string intToBina(int x) {
        string str;
        while (x) {
            str = char(x % 2 + '0') + str;
            x /= 2;
        }
        return str;
    }
};
int main() {
    Solution sol;
    vector<int> res = sol.grayCode(5);
    for (int x : res) {
        cout << x << ' ';
    }
    cout << "\n";
    system("pause");
    return 0;
}