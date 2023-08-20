#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int sSize = s.size();
        int i = 0;
        while (i < sSize - i - 1) {
            // int temp = s[i];
            // s[i] = s[sSize - i - 1];
            // s[sSize - i - 1] = temp;
            swap(s[i], s[sSize - i - 1]);
            ++i;
        }
    }
};
int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution sol;
    sol.reverseString(s);
    for (const char& ch : s) {
        cout << ch << ' ';
    }
    system("pause");
    return 0;
}