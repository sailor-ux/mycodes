#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int sLen = s.size(), pLen = p.size();
        if (sLen < pLen) {
            return ans;
        }
        vector<int> sCount(26), pCount(26);
        for (int i = 0; i < pLen; i++) {
            sCount[s[i] - 'a']++;
            pCount[p[i] - 'a']++;
        }
        if (sCount == pCount) {
            ans.push_back(0);
        }
        for (int i = pLen; i < sLen; i++) {
            sCount[s[i - pLen] - 'a']--;
            sCount[s[i] - 'a']++;
            if (sCount == pCount) {
                ans.push_back(i - pLen + 1);
            }
        }
        return ans;
    }
};
int main() {

    system("pause");
    return 0;
}