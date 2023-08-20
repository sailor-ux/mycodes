#include <iostream>
#include <vector>
using namespace std;
class Trie {
private:
    vector<Trie*> children;
    bool isEnd;
    Trie* searchPrefix(string prefix) {
        Trie* root = this;
        for (char& ch : prefix) {
            ch -= 'a';
            if (root->children[ch] == nullptr) {
                return nullptr;
            }
            root = root->children[ch];
        }
        return root;
    }

public:
    Trie() : children(26), isEnd(false) {
    }

    void insert(string word) {
        Trie* root = this;
        for (const char& ch : word) {
            int index = ch - 'a';
            if (root->children[index] == nullptr) {
                root->children[index] = new Trie();
            }
            root = root->children[index];
        }
        root->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};
int main() {

    system("pause");
    return 0;
}