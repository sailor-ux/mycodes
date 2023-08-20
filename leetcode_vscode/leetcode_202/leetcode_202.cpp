#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        st.insert(n); // 可有可无！有更好，或许快一步返回false！
        while (1) {
            int sum = 0, num = 0;
            while (n) {
                num = n % 10;
                sum += (num * num);
                n /= 10;
            }
            if (sum == 1) {
                return true;
            } else if (st.find(sum) != st.end()) {
                return false;
            }
            st.insert(sum);
            n = sum;
        }
    }
};
int main() {

    system("pause");
    return 0;
}