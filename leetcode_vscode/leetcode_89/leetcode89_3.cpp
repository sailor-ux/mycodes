#include <cmath>
#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
  public:
    // 回溯法（去找所有可能的结果）
    vector<vector<int>> grayCode(int n) {
        vector<int> res;
        vector<vector<int>> ress;
        unordered_set<int> record;
        dfs(res, ress, record, n);
        return ress;
    }
    void dfs(vector<int>& res, vector<vector<int>>& ress, unordered_set<int>& record, int& n) {
        if (res.size() == pow(2, n)) {
            if (isMatch(res[0], res.back())) {
                ress.push_back(res);
            }
            return;
        }
        for (int i = 0; i < pow(2, n); i++) {
            if (record.find(i) == record.end() && (res.empty() || isMatch(i, res.back()))) {
                if (!res.empty() || !i) {
                    res.push_back(i);
                    record.insert(i);
                    dfs(res, ress, record, n);
                    res.pop_back();
                    record.erase(i);
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
    vector<vector<int>> ress = sol.grayCode(5);
    for (vector<int> res : ress) {
        for (int x : res) {
            cout << x << ' ';
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}