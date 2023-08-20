#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        string data;
        data += to_string(root->val) + ',';
        data += serialize(root->left);
        data += serialize(root->right);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) { //给定二叉搜索树的先序遍历，唯一地重建出这棵树！
        if (data.empty()) {
            return nullptr;
        }
        vector<int> arr = split(data, ',');
        return construct(arr);
    }

    vector<int> split(const string& data, char symbol) {
        vector<int> res;
        int pos = 0;
        while (pos < data.length()) {
            int start = pos;
            while (pos < data.length() && data[pos] != symbol) {
                pos++;
            }
            res.push_back(stoi(data.substr(start, pos - start)));
            pos++;
        }
        return res;
    }

    TreeNode* construct(vector<int>& arr) {
        if (arr.empty()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(arr[0]);
        if (arr.size() > 1) {
            int l = 1, r = arr.size() - 1, pos = 0; // pos二分查找右子树的起始位置
            while (l <= r) {
                int mid = (l + r) / 2;
                if (arr[mid] > arr[0]) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            vector<int> arrLeftTree, arrRightTree;
            if (pos != 0) {
                arrLeftTree.assign(arr.begin() + 1, arr.begin() + pos);
                arrRightTree.assign(arr.begin() + pos, arr.end());
            } else {
                arrLeftTree.assign(arr.begin() + 1, arr.end());
            }
            root->left = construct(arrLeftTree);
            root->right = construct(arrRightTree);
        }
        return root;
    }
};
int main() {
    Codec obj;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    TreeNode* node = obj.deserialize(obj.serialize(root));
    system("pause");
    return 0;
}