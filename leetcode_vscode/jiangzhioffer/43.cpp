#include <iostream>
#include <math.h>
#include <string>
using namespace std;
class Solution {
public:
    /* int countDigitOne(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            count += number1Sum(i);
        }
        return count;
    }
    int number1Sum(int n) {
        int count = 0;
        while (n) {
            if (n % 10 == 1) {
                count++;
            }
            n /= 10;
        }
        return count;
    } */
    int countDigitOne(int n) {
        string str = to_string(n);
        int len = str.length();
        if (len == 1) {
            return 1;
        }
        int count = 0;
        for (int i = 1; i < len - 1; i++) { // i=0或者n-1不适用substr函数，单独考虑
            int sum = stoi(str.substr(0, i));
            sum *= pow(10, len - 1 - i);
            count += sum;
            if (str[i] == '0') {
                continue;
            }
            if (str[i] == '1') {
                count += stoi(str.substr(i + 1)) + 1;
            } else {
                count += pow(10, len - 1 - i);
            }
        }
        if (str[0] == '1') {
            count += stoi(str.substr(1)) + 1;
        } else if (str[0] > '1') {
            count += pow(10, len - 1);
        }
        count += stoi(str.substr(0, len - 1)); // len=1这里substr函数不适用，单独考虑
        if (str[len - 1] >= '1') {
            count++;
        }
        return count;
    }
};
int main() {
    Solution sol;
    cout << sol.countDigitOne(9);
    system("pause");
    return 0;
}