#include <iostream>
#include <vector>
using namespace std;
class TrieNode { // 用这个类来定义字典树(前缀树)的结点，结点是属于这个类TrieNode的对象
public:
    bool isWord;
    vector<TrieNode*> children; // 装载子结点(的指针)
    TrieNode() : isWord(false), children(26) {
    }
};
class Trie { // 用这个类来定义字典树(前缀树)，字典树(前缀树)是属于这个类Trie的对象
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (!cur->children[idx]) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->isWord = true;
    }

    bool search(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (!cur->children[idx]) {
                return false;
            }
            cur = cur->children[idx];
        }
        return cur->isWord;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.length(); i++) {
            int idx = prefix[i] - 'a';
            if (!cur->children[idx]) {
                return false;
            }
            cur = cur->children[idx];
        }
        return true;
    }
};
int main() {

    system("pause");
    return 0;
}