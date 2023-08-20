#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> mp{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string combination;
        vector<string> combinations;
        dfs(digits, mp, combination, combinations, 0);
        return combinations;
    }
    void dfs(const string& digits, const vector<string>& mp, string& combination, vector<string>& combinations, int idx) {
        if (idx == digits.length()) {
            combinations.push_back(combination);
            return;
        }
        int number = digits[idx] - '0';
        for (const char& ch : mp[number - 2]) {
            combination.push_back(ch);
            dfs(digits, mp, combination, combinations, idx + 1);
            combination.pop_back();
        }
    }
};
int main() {

    system("pause");
    return 0;
}