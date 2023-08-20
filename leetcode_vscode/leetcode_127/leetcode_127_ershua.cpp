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
        unordered_set<string> wordListMap(wordList.begin(), wordList.end());
        if (!wordListMap.count(endWord)) {
            return 0;
        }
        unordered_map<string, int> mp;
        mp[beginWord] = 1;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            for (int i = 0; i < word.length(); i++) {
                string newWord = word;
                for (int j = 0; j < 26; j++) {
                    newWord[i] = j + 'a';
                    if (wordListMap.count(newWord)) {
                        if (newWord == endWord) {
                            return mp[word] + 1;
                        }
                        if (!mp.count(newWord)) {
                            q.push(newWord);
                            mp[newWord] = mp[word] + 1;
                        }
                    }
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordListMap(wordList.begin(), wordList.end());
        if (!wordListMap.count(endWord)) {
            return 0;
        }
        unordered_set<string> seen;
        int len = 1;
        queue<string> q;
        q.push(beginWord);
        seen.insert(beginWord);
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                string word = q.front();
                q.pop();
                for (int i = 0; i < word.length(); i++) {
                    string newWord = word;
                    for (int j = 0; j < 26; j++) {
                        newWord[i] = j + 'a';
                        if (wordListMap.count(newWord)) {
                            if (newWord == endWord) {
                                return len + 1;
                            }
                            if (!seen.count(newWord)) {
                                q.push(newWord);
                                seen.insert(newWord);
                            }
                        }
                    }
                }
            }
            len++; // 自己想的！
        }
        return 0;
    }
    // 双向BFS
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) {
            return 0;
        }
        unordered_set<string> s1{beginWord}, s2{endWord};
        int step = 2;
        while (!s1.empty() && !s2.empty()) {
            for (const string& word : s1) {
                dict.erase(word);
            }
            for (const string& word : s2) {
                dict.erase(word);
            }
            if (s1.size() > s2.size()) {
                swap(s1, s2);
            }
            unordered_set<string> s;
            for (string word : s1) { // 遍历一个set不能传引用！
                for (int i = 0; i < word.length(); i++) {
                    char ch = word[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        word[i] = j;
                        if (s2.count(word)) {
                            return step;
                        }
                        if (!dict.count(word)) {
                            continue;
                        }
                        s.insert(word);
                    }
                    word[i] = ch;
                }
            }
            s1 = s;
            step++;
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) {
            return 0;
        }
        unordered_set<string> s1{beginWord}, s2{endWord};
        int step = 2;
        while (!s1.empty() && !s2.empty()) {
            for (const string& word : s1) {
                dict.erase(word);
            }
            for (const string& word : s2) {
                dict.erase(word);
            }
            if (s1.size() > s2.size()) {
                swap(s1, s2);
            }
            unordered_set<string> s;
            for (string word : s1) { // 遍历一个set不能传引用！
                for (int i = 0; i < word.length(); i++) {
                    string newWord = word;
                    for (char j = 'a'; j <= 'z'; j++) {
                        newWord[i] = j;
                        if (s2.count(newWord)) {
                            return step;
                        }
                        if (!dict.count(newWord)) {
                            continue;
                        }
                        s.insert(newWord);
                    }
                }
            }
            step++;
            s1 = s;
        }
        return 0;
    }
};
int main() {
    unordered_set<string> st{"abs", "abc"};
    cout << st.erase("xxx") << endl; // set要删除的元素如果在集合中本身就不存在，那么返回0！！！
    cout << st.erase("abs");
    system("pause");
    return 0;
}