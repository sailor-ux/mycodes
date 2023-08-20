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
//��list<string>, ���죡
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "#,";
        }
        string str;
        str += to_string(root->val) + ",";
        str += serialize(root->left);
        str += serialize(root->right);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;
        // ��һ�и����Ǹ���������������ã�
        /* for (int i = 0; i < data.length(); i++) {
            if (isdigit(data[i])) {
                while (isdigit(data[i])) {
                    str.push_back(data[i++]);
                }
                dataArray.push_back(str);
                str.clear();
            } else {
                dataArray.push_back("#");
                i++;
            }
        } */
        // ��������ã�
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
            return nullptr;
        }
        // string=>int, ��һ�и����Ǹ�����������stoi���㣡
        /* int value = 0;
        for (const char& ch : dataArray.front()) {
            value = 10 * value + ch - '0';
        } */

        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = dfs(dataArray);
        root->right = dfs(dataArray);
        return root;
    }
};
int main() {

    system("pause");
    return 0;
}