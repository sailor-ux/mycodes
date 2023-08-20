#include <iostream>
#include <vector>
using namespace std;
class TrieNode { // ��������������ֵ���(ǰ׺��)�Ľ�㣬��������������TrieNode�Ķ���
public:
    bool isWord;
    vector<TrieNode*> children; // װ���ӽ��(��ָ��)
    TrieNode() : isWord(false), children(26) {
    }
};
class Trie { // ��������������ֵ���(ǰ׺��)���ֵ���(ǰ׺��)�����������Trie�Ķ���
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