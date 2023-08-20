#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> mapST(26, -1), mapTS(26, -1);
        for (int i = 0; i < s.length(); i++) {
            if (mapST[s[i] - 'a'] == -1) {
                if (mapTS[t[i] - 'a'] != -1) {
                    return false;
                }
                mapST[s[i] - 'a'] = t[i] - 'a';
                mapTS[t[i] - 'a'] = s[i] - 'a';
            } else if (mapST[s[i] - 'a'] != t[i] - 'a') {
                return false;
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, char> mapST, mapTS;
        for (int i = 0; i < s.length(); i++) {
            if (!mapST.count(s[i])) {
                if (mapTS.count(t[i])) {
                    return false;
                }
                mapST[s[i]] = t[i];
                mapTS[t[i]] = s[i];
            } else if (mapST[s[i]] != t[i]) {
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