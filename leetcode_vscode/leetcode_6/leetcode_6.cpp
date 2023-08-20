#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // ×Ö·û´®Ä£ÄâÌâ£¡
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string res;
        vector<string> vec(numRows);
        int i = 0;
        bool flag = true;
        for (const char& ch : s) {
            vec[i].push_back(ch);
            if (i == 0) {
                flag = true;
            } else if (i + 1 == numRows) {
                flag = false;
            }
            flag ? i++ : i--;
        }
        for (const string& str : vec) {
            res += str;
        }
        return res;
    }
};
int main() {
    Solution sol;
    cout << sol.convert("PAYPALISHIRING", 1);
    system("pause");
    return 0;
}