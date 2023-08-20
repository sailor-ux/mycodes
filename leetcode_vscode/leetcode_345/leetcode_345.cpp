#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> st{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n = s.length();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j && !st.count(s[i])) { //小心别又换回去了！！
                i++;
            }
            while (j > i && !st.count(s[j])) {
                j--;
            }
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};
int main() {
    Solution sol;
    cout << sol.reverseVowels("leetcode");
    system("pause");
    return 0;
}