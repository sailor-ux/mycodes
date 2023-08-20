#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> num2strSmall, num2strMedium, num2strLarge;
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        this->num2strSmall = vector<string>{"Zero",
                                            "One",
                                            "Two",
                                            "Three",
                                            "Four",
                                            "Five",
                                            "Six",
                                            "Seven",
                                            "Eight",
                                            "Nine",
                                            "Ten",
                                            "Eleven",
                                            "Twelve",
                                            "Thirteen",
                                            "Fourteen",
                                            "Fifteen",
                                            "Sixteen",
                                            "Seventeen",
                                            "Eighteen",
                                            "Nineteen"};
        this->num2strMedium = vector<string>{
            "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        this->num2strLarge = vector<string>{
            "Billion",
            "Million",
            "Thousand",
            "",
        };
        string ans = "";
        for (int i = int(1e9), j = 0; i >= 1; i /= 1000, j++) {
            if (num < i) {
                continue;
            }
            ans += num2str(num / i) + num2strLarge[j] + " ";
            num %= i;
        }
        while (ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
    string num2str(int x) {
        string ans = "";
        if (x >= 100) {
            ans += num2strSmall[x / 100] + " " + "Hundred" + " ";
            x %= 100;
        }
        if (x >= 20) {
            ans += num2strMedium[x / 10] + " ";
            x %= 10;
        }
        if (x != 0) {
            ans += num2strSmall[x] + " ";
        }
        return ans;
    }
};
int main() {
    Solution sol;
    cout << sol.numberToWords(1234567);
    system("pause");
    return 0;
}