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
    ListNode* reverseKGroup(ListNode* head, int k) { // ����Ҳ�뵽�ݹ�
        ListNode* dummyHead = new ListNode(-1, head);
        int count = 0;
        while (head) {
            if (++count == k) {
                break;
            }
            head = head->next;
        }
        if (!head) { // ���������k���������head==nullptr����count<k��˵������k��
            return dummyHead->next;
        }
        ListNode* nextHead = reverseKGroup(head->next, k);
        head->next = nullptr;
        ListNode* newHead = reverseList(dummyHead->next);
        dummyHead->next->next = nextHead;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) { // ��ת����ݹ鷨
        if (!head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head; // ��ת
        head->next = nullptr;    // �ÿ�
        return newHead;
    }
};
int main() {
    vector<int> arr{1, 2, 3, 4, 5, 6};
    ListNode *head = new ListNode(arr[0]), *dummyHead = new ListNode(-1, head);
    for (int i = 1; i < arr.size(); i++) {
        head->next = new ListNode(arr[i]);
        head = head->next;
    }
    head = dummyHead->next;
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
    Solution sol;
    head = sol.reverseKGroup(dummyHead->next, 2);
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    system("pause");
    return 0;
}