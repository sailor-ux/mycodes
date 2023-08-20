#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> cnt(123, 0);
        for (const char& ch : s) {
            cnt[ch]++;
        }
        /* for (int i = 0; i < 123; i++) {
            if (cnt[i] == 1) {
                return char(i);
            }
        } */
        for (const char& ch : s) {
            if (cnt[ch] == 1) {
                return ch;
            }
        }
        return ' ';
    }
};
int main() {

    system("pause");
    return 0;
}