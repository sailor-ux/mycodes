#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    // 用数组替代哈希表！！！
    bool isAnagram(string s, string t) {
        vector<int> vec(26);
        if (s.length() != t.length()) {
            return false;
        }
        for (int i = 0; i < s.length(); i++) {
            vec[s[i] - 'a']++;
            vec[t[i] - 'a']--;
        }
        for (const int& x : vec) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }
};
int main() {

    system("pause");
    return 0;
}