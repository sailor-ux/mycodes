#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 栈实现
    vector<int> reversePrint(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* node = head;
        while (node) {
            stk.push(node);
            node = node->next;
        }
        vector<int> res;
        while (!stk.empty()) {
            res.push_back(stk.top()->val);
            stk.pop();
        }
        return res;
    }
    // 递归实现
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        dfs(head, res);
        return res;
    }
    void dfs(ListNode* head, vector<int>& res) {
        if (!head) {
            return;
        }
        if (!head->next) {
            res.push_back(head->val);
            return;
        }
        dfs(head->next, res);
        res.push_back(head->val);
    }
};
int main() {

    system("pause");
    return 0;
}