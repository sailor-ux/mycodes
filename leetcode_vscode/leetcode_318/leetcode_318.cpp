#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), maxProd = 0;
        vector<int> masks; // 长度也为n
        for (const string& word : words) {
            int mask = 0;
            for (const char& ch : word) {
                mask |= 1 << ch - 'a';
            }
            masks.push_back(mask);
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((masks[i] & masks[j]) == 0) {
                    maxProd = max(maxProd, int(words[i].length() * words[j].length()));
                }
            }
        }
        return maxProd;
    }
};
int main() {
    Solution sol;
    vector<string> words{"a", "aa", "aaa", "aaaa"};
    cout << sol.maxProduct(words);
    system("pause");
    return 0;
}