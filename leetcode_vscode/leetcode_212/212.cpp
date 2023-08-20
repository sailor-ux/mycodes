#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
struct TrieNode {
    string word; // isWord=T,wordÊÇÇ°×º×Ö·û´®; isWord=F,wordÎª¿Õ
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        this->word = "";
    }
};
void insertWord(TrieNode* root, const string& word) {
    TrieNode* cur = root;
    for (int i = 0; i < word.length(); i++) {
        char ch = word[i];
        if (!cur->children.count(ch)) {
            cur->children[ch] = new TrieNode();
        }
        cur = cur->children[ch];
    }
    cur->word = word;
}

class Solution {
public:
    vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (auto& word : words) {
            insertWord(root, word);
        }
        set<string> res;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, root, res, i, j);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
    void dfs(vector<vector<char>>& board, TrieNode* root, set<string>& res, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == '#') {
            return;
        }
        char ch = board[x][y];
        if (!root->children.count(ch)) {
            return;
        }
        root = root->children[ch];
        if (root->word != "") {
            res.insert(root->word);
        }
        board[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            dfs(board, root, res, nx, ny);
        }
        board[x][y] = ch;
    }
};
int main() {

    system("pause");
    return 0;
}