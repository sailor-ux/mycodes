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
    // �ݹ鷨
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
    // ������
    // pre��pre֮ǰ�Ѿ���ɷ�ת��cur��cur֮����ԭ˳��ȴ���ת������cur��pre��ָ��
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* nextNode = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextNode;
        }
        return pre;
    }
};
int main() {

    system("pause");
    return 0;
}