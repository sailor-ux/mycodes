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
// 序列化与反序列化的规则是采用先序遍历！
// 这里的先序遍历，空节点会记作None，所以由先序遍历可以唯一地构建出二叉树！！！
// vector是数组，连续存储的，每次删除开头都是o(n)的时间复杂度
// list是链表，链表增删都是常数o(1)
// vector是会超时的！！！
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // if (!root) {
        //     return "None,";
        // }
        // string str;
        // str += to_string(root->val) + ',';
        // str += serialize(root->left);
        // str += serialize(root->right);
        // return str;
        string str;
        dfs(root, str);
        return str;
    }
    void dfs(TreeNode* root, string& str) {
        if (!root) {
            str += "None,";
            return;
        }
        str += to_string(root->val) + ',';
        dfs(root->left, str);
        dfs(root->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;
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
        if (dataArray.front() == "None") {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = dfs(dataArray);  // dataArray抹去最前面的根节点，剩下的用来构建左子树
        root->right = dfs(dataArray); // 构建完左子树之后，再剩下的用来构建右子树
        return root;
    }
};
int main() {

    system("pause");
    return 0;
}