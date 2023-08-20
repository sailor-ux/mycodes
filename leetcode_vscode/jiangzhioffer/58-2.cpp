#include <iostream>
using namespace std;
class Solution {
public:
    // ²»ÓÃÇÐÆ¬º¯Êýsubstr£¡
    string reverseLeftWords(string s, int n) {
        string str(s.length(), ' ');
        for (int i = 0; i < s.length(); i++) {
            if (i < n) {
                str[s.length() - n + i] = s[i];
            } else {
                str[i - n] = s[i];
            }
        }
        return str;
    }
};
int main() {

    system("pause");
    return 0;
}