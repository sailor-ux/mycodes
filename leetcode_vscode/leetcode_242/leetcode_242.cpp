#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    // 只用一个哈希表！
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashMap;
        if (s.length() != t.length()) {
            return false;
        }
        for (int i = 0; i < s.length(); i++) {
            hashMap[s[i]]++;
            hashMap[t[i]]--;
        }
        for (unordered_map<char, int>::iterator it = hashMap.begin(); it != hashMap.end(); it++) {
            if (it->second != 0) {
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