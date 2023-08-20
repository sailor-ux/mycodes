#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    // 单向BFS
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) {
            return 0;
        }
        unordered_map<string, int> mp_seen; //<word, 搜索到word时路径的长度>
        queue<string> q;
        q.push(beginWord);
        mp_seen[beginWord] = 1;
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int pathLen = mp_seen[word];
            for (int i = 0; i < word.length(); i++) {
                string newWord = word;
                for (int j = 0; j < 26; j++) {
                    newWord[i] = j + 'a';
                    if (newWord == endWord) {
                        return pathLen + 1; // 如果转换路径存在，在此返回
                    }
                    if (mp_seen.find(newWord) == mp_seen.end() && st.find(newWord) != st.end()) {
                        q.push(newWord);
                        mp_seen[newWord] = pathLen + 1;
                    }
                }
            }
        }
        return 0; // 如果转换路径不存在，在此返回
    }
};
int main() {

    system("pause");
    return 0;
}