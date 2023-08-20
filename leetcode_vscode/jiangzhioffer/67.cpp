#include <iostream>
using namespace std;
class Solution {
public:
    int strToInt(string str) {
        int res = 0;
        bool isNeg = false;
        int n = str.length();
        int i = 0;
        while (str[i] == ' ') {
            i++;
        }
        if (str[i] == '-') {
            isNeg = true;
        }
        if (str[i] == '+' || str[i] == '-') {
            i++;
        }
        while (i < n && isdigit(str[i])) {
            int num = str[i] - '0';
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && num > INT_MAX % 10)) {
                return isNeg ? INT_MIN : INT_MAX;
            }
            res = res * 10 + num;
            i++;
        }
        return isNeg ? -res : res;
    }
};
int main() {

    system("pause");
    return 0;
}