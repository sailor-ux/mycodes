#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> printNumbers(int n) {
        vector<string> numbers;
        string number(n, '0');
        while (!Increment(number, n)) { // 字符串number表示的数字+1，并判断是否溢出(是否超过n位)
            printNumber(numbers, number, n);
        }
        return numbers;
    }
    bool Increment(string& number, const int& n) {
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            int sum = number[i] - '0' + cnt;
            if (i == n - 1) {
                sum++;
            }
            if (sum >= 10) {
                if (i == 0) {
                    return true;
                }
                sum -= 10;
                cnt = 1;
                number[i] = '0' + sum;
            } else {
                number[i] = '0' + sum;
                return false;
            }
        }
        return false;
    }
    void printNumber(vector<string>& numbers, const string& number, const int& n) {
        int i = 0;
        for (; i < n; i++) {
            if (number[i] != '0') {
                break;
            }
        }
        numbers.push_back(number.substr(i));
    }
};
int main() {
    Solution sol;
    vector<string> numbers = sol.printNumbers(1000000000);
    /* for (const string& number : numbers) {
        cout << number << "\n";
    } */
    cout << numbers.back();
    system("pause");
    return 0;
}