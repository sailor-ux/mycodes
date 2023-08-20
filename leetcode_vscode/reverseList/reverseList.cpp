#include <iostream>
#include <vector>
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
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return true;
        }
        ListNode* midNode = findMidNode(head);          // 中间结点左偏
        ListNode* newHead = reverseList(midNode->next); // 前半部分不动，后半部分反转(更短)
        ListNode *p1 = head, *p2 = newHead;             // p1前半部分，长；p2反转之后的后半部分，短
        while (p1 && p2) {                              // p2先为nullptr，当p2=nullptr时，整个都比完了，是回文链表，return T
            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        reverseList(newHead);
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
    ListNode* findMidNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // 奇数个结点：slow恰在中间；偶数个结点：slow左偏
    }
};
int main() {
    Solution sol;
    vector<int> vec{1, 3, 2, 9, 8, 2, 3, 1};
    ListNode* head = new ListNode(vec[0]);
    ListNode* temp = head;
    for (int i = 1; i < vec.size(); i++) {
        temp->next = new ListNode(vec[i]);
        temp = temp->next;
    }
    cout << sol.isPalindrome(head) << endl;
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    system("pause");
    return 0;
}