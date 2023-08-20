#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_set<int> res;
        int oneWordLen = words[0].length(), wordSum = words.size();
        int allWordsLen = oneWordLen * wordSum;
        if (s.length() < allWordsLen) {
            return {};
        }
        unordered_map<string, int> wordsHash;
        for (const string& word : words) {
            wordsHash[word]++;
        }
        unordered_map<string, int> tempHash;
        for (int i = 0; i <= s.length() - allWordsLen; i++) {
            int left = i, right = i;
            while (right + oneWordLen <= s.length()) {
                string str = s.substr(right, oneWordLen);
                right += oneWordLen;
                if (wordsHash.find(str) == wordsHash.end()) {
                    left = right;
                    tempHash.clear();
                } else {
                    tempHash[str]++;
                    if (isHashMatch(tempHash, wordsHash) && res.find(left) == res.end()) {
                        res.insert(left);
                        tempHash.clear();
                        break;
                    }
                }
            }
        }
        vector<int> arr;
        for (int x : res) {
            arr.push_back(x);
        }
        return arr;
    }
    bool isHashMatch(const unordered_map<string, int>& tempHash, unordered_map<string, int>& wordsHash) {
        if (tempHash.size() < wordsHash.size()) {
            return false;
        }
        for (unordered_map<string, int>::iterator it = wordsHash.begin(); it != wordsHash.end(); it++) {
            if (tempHash.at(it->first) != it->second) {
                return false;
            }
        }
        return true;
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

// while (tempHash.at(str) > wordsHash.at(str)) {
//     string word = s.substr(left, oneWordLen);
//     tempHash[word]--;
//     left += oneWordLen;
// }