#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
  public:
    // hard ºÃÄÑ£¡£¡£¡
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int oneWordLen = words[0].length(), wordSum = words.size();
        int allWordsLen = oneWordLen * wordSum;
        if (s.length() < allWordsLen) {
            return res;
        }
        unordered_map<string, int> wordsHash;
        for (const string& word : words) {
            wordsHash[word]++;
        }
        unordered_map<string, int> tempHash;
        for (int i = 0; i < oneWordLen; i++) {
            int left = i, right = i, count = 0;
            tempHash.clear();
            while (right + oneWordLen <= s.length()) {
                string str = s.substr(right, oneWordLen);
                right += oneWordLen;
                if (wordsHash.find(str) == wordsHash.end()) {
                    left = right;
                    count = 0;
                    tempHash.clear();
                } else {
                    tempHash[str]++;
                    count++;
                    while (tempHash.at(str) > wordsHash.at(str)) {
                        string word = s.substr(left, oneWordLen);
                        tempHash[word]--;
                        count--;
                        left += oneWordLen;
                    }
                    if (count == words.size()) {
                        res.push_back(left);
                    }
                }
            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    string s = "barfoothefoobarman";
    vector<string> words{"foo", "bar"};
    vector<int> res = sol.findSubstring(s, words);
    for (int x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}