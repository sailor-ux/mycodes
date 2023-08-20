#include <iostream>
using namespace std;
class Solution {
public:
    bool isAdditiveNumber(string num) {
        return dfs(num, 0, 0, 0, 0);
    }
    bool dfs(string num, int index, int count, long prevprev, long prev) {
        if (index == num.length()) {
            if (count == 1 || count == 2) {
                return false;
            }
            return true;
        }
        long current = 0;
        for (int i = index; i < num.length(); i++) {
            if (num[index] == '0' && i == index + 1) {
                return false;
            }
            char ch = num[i];
            current = current * 10 + ch - '0';
            if (current > 99999999999999999) { //防止溢出 这是17位的9
                return false;
            }
            if (count >= 2) {
                if (current > prevprev + prev) {
                    return false;
                } else if (current < prevprev + prev) {
                    continue;
                } else {
                    return dfs(num, i + 1, count + 1, prev, current);
                }
            } else {
                if (dfs(num, i + 1, count + 1, prev, current)) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main() {

    system("pause");
    return 0;
}