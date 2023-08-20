#include <iostream>
#include <list>
using namespace std;
class Solution {
public:
    bool isValidSerialization(string preorder) {
        list<string> dataArray;
        for (int i = 0; i < preorder.length(); i++) {
            if (preorder[i] == '#') {
                dataArray.push_back("#");
                i++;
            } else if (isdigit(preorder[i])) {
                string str;
                while (i < preorder.length() && isdigit(preorder[i])) {
                    str.push_back(preorder[i++]);
                }
                dataArray.push_back(str);
            }
        }
        return dfs(dataArray) && dataArray.empty();
    }
    bool dfs(list<string>& dataArray) {
        if (dataArray.empty()) {
            return false;
        }
        if (dataArray.front() == "#") {
            dataArray.erase(dataArray.begin());
            return true;
        }
        dataArray.erase(dataArray.begin());
        if (!dfs(dataArray)) {
            return false;
        }
        if (!dfs(dataArray)) { // 构建完左子树，剩下的dataArray用来构建右子树，它要是为空，那么肯定false
            return false;
        }
        return true;
    }
};
int main() {
    Solution sol;
    cout << sol.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#");
    system("pause");
    return 0;
}