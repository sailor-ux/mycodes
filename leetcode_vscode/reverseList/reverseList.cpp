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
        ListNode* midNode = findMidNode(head);          // �м�����ƫ
        ListNode* newHead = reverseList(midNode->next); // ǰ�벿�ֲ�������벿�ַ�ת(����)
        ListNode *p1 = head, *p2 = newHead;             // p1ǰ�벿�֣�����p2��ת֮��ĺ�벿�֣���
        while (p1 && p2) {                              // p2��Ϊnullptr����p2=nullptrʱ�������������ˣ��ǻ�������return T
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
        return slow; // ��������㣺slowǡ���м䣻ż������㣺slow��ƫ
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