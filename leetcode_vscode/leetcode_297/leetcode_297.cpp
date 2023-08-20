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
// ���л��뷴���л��Ĺ����ǲ������������
// ���������������սڵ�����None�������������������Ψһ�ع�����������������
// vector�����飬�����洢�ģ�ÿ��ɾ����ͷ����o(n)��ʱ�临�Ӷ�
// list������������ɾ���ǳ���o(1)
// vector�ǻᳬʱ�ģ�����
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
        root->left = dfs(dataArray);  // dataArrayĨȥ��ǰ��ĸ��ڵ㣬ʣ�µ���������������
        root->right = dfs(dataArray); // ������������֮����ʣ�µ���������������
        return root;
    }
};
int main() {

    system("pause");
    return 0;
}