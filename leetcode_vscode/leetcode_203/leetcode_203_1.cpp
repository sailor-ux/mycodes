#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    // ÎÒÐ´µÄµÝ¹é
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(-1, head);
        dfs(dummyHead, val);
        return dummyHead->next;
    }
    void dfs(ListNode* head, const int& val) {
        if (!head->next) {
            return;
        }
        if (head->next->val == val) {
            head->next = head->next->next;
            dfs(head, val);
        } else {
            dfs(head->next, val);
        }
    }
};
int main() {

    system("pause");
    return 0;
}