#include <iostream>
#include <list>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec { // ���������л������Ƿ����л�������������������ҵĵݹ飡����
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        dfs(root, str);
        return str;
    }
    void dfs(TreeNode* root, string& str) {
        if (!root) {
            str += "#,";
            return;
        }
        str += to_string(root->val) + ',';
        dfs(root->left, str);
        dfs(root->right, str);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str = "";
        for (const char& ch : data) {
            if (ch != ',') {
                str.push_back(ch);
            } else {
                dataArray.push_back(str);
                str.clear();
            }
        }
        return dfs(dataArray);
    }
    TreeNode* dfs(list<string>& dataArray) {
        if (dataArray.front() == "#") {
            dataArray.erase(dataArray.begin());
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = dfs(dataArray);  // dataArrayĨȥ��ǰ��ĸ��ڵ㣬ʣ�µ���������������
        root->right = dfs(dataArray); // ������������֮����ʣ�µ���������������
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main() {

    system("pause");
    return 0;
}