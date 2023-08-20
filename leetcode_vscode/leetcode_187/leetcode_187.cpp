#include <bitset>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    // bitset<n> n位0；可以替代长度为n，每个元素是 0/1 (true/false) 的数组
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int n = s.length();
        unordered_map<char, int> hashMap{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        bitset<1 << 20> bs1, bs2;
        int val = 0, mask = (1 << 20) - 1;
        for (int i = 0; i < 10; i++) {
            val = val << 2 | hashMap[s[i]];
        }
        bs1.set(val);
        for (int i = 10; i < n; i++) {
            val = ((val << 2) & mask) | hashMap[s[i]];
            if (bs2.test(val)) { // val对应的子字符串的这种情况(包括现在的话，至少出现了三次)，已经出现过两次了，已经入过栈、加入过res中了，而现在是第三次、第四次碰到....
                continue;
            }
            if (bs1.test(val)) {
                bs2.set(val);
                res.push_back(s.substr(i - 9, 10));
                continue;
            }
            bs1.set(val);
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}