#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> arr(123);
        for (char ch : s) {
            arr[ch]++;
        }
        int count = 0;
        for (int i = 65; i < 123; i++) {
            count += arr[i] % 2;
        }
        return count > 1 ? s.length() - count + 1 : s.length();
    }
};
int main() {

    system("pause");
    return 0;
}