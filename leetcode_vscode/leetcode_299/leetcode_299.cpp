#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int bullsNum = 0, cowsNum = 0;
        vector<int> countS(10), countG(10);
        int sLen = secret.length(), gLen = guess.length();
        int maxLen = max(sLen, gLen);
        for (int i = 0; i < maxLen; i++) {
            if (i < sLen && i < gLen && secret[i] == guess[i]) {
                bullsNum++;
                continue;
            }
            if (i < sLen) {
                countS[secret[i] - '0']++;
            }
            if (i < gLen) {
                countG[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; i++) {
            cowsNum += min(countS[i], countG[i]);
        }
        return to_string(bullsNum) + 'A' + to_string(cowsNum) + 'B';
    }
};
int main() {

    system("pause");
    return 0;
}