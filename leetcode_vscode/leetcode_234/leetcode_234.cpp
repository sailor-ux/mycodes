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
    ListNode* frontNode;
    bool isPalindrome(ListNode* head) {
        frontNode = head;
        return dfs(frontNode);
    }
    bool dfs(ListNode* curNode) {
        if (curNode != nullptr) {
            if (!dfs(curNode->next)) {
                return false;
            }
            if (curNode->val != frontNode->val) {
                return false;
            }
            frontNode = frontNode->next;
        }
        return true;
    }
};