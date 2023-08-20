#include <iostream>
#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//≤ª”√list<string>!
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        /* if (!root) {
            return "#,";
        }
        string str;
        str += to_string(root->val) + ",";
        str += serialize(root->left);
        str += serialize(root->right);
        return str; */
        string str;
        dfs(root, str);
        return str;
    }

    void dfs(TreeNode* root, string& str) {
        if (!root) {
            str += "#,";
            return;
        }
        str += to_string(root->val) + ",";
        dfs(root->left, str);
        dfs(root->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return dfs(data);
    }
    TreeNode* dfs(string& data) {
        int i = 0;
        if (data[i] == '#') {
            data = data.substr(i + 2);
            return nullptr;
        } else {
            int value = 0, sign = 1;
            if (data[i] == '-') {
                sign = -1;
                i++;
            }
            while (isdigit(data[i])) {
                value = 10 * value + data[i++] - '0';
            }
            TreeNode* root = new TreeNode(sign * value);
            data = data.substr(i + 1);
            root->left = dfs(data);
            root->right = dfs(data);
            return root;
        }
    }
};
int main() {

    system("pause");
    return 0;
}