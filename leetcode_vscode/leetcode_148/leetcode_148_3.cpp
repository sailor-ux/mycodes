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
    // ���Ž⣡���� �ܾ��䣡���� ��Ҫ�ظ�ˢ������
    ListNode* sortList(ListNode* head) {
        if (!head) {
            return head;
        }
        int length = 0;
        ListNode* node = head;
        while (node) {
            length++;
            node = node->next;
        }
        ListNode* dummyHead = new ListNode(-1, head);
        for (int size = 1; size < length; size <<= 1) { // size<=length��ɣ�����size=lengthû��Ҫ��forѭ�����˷�ʱ��
            auto curr = dummyHead->next;
            auto tail = dummyHead;
            while (curr) {
                auto left = curr;             // ָ���һ�����
                auto right = cut(left, size); // null
                curr = cut(right, size);      // null
                tail->next = mergeTwoList(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        return dummyHead->next;
    }
    ListNode* cut(ListNode* head, int n) { // headָ���������ֳ���������(ǰn���ͺ����)�����غ��������ͷָ��
        ListNode* node = head;
        while (n > 1 && node) { // --n
            node = node->next;
            n--;
        }
        if (!node) {
            return nullptr;
        }
        ListNode* temp = node->next;
        node->next = nullptr;
        return temp;
    }
    ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode();
        ListNode* currNode = dummyHead;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                currNode->next = list1;
                list1 = list1->next;
            } else {
                currNode->next = list2;
                list2 = list2->next;
            }
            currNode = currNode->next;
        }
        if (list1) {
            currNode->next = list1;
        }
        if (list2) {
            currNode->next = list2;
        }
        return dummyHead->next;
    }
};
int main() {

    system("pause");
    return 0;
}