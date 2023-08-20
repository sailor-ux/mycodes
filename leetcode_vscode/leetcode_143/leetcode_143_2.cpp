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
    void reorderList(ListNode* head) {
        ListNode* midNode = middleNode(head);
        ListNode* list2 = reverseList(midNode->next); // list2�����е�Ԫ����Ҫ�����list1������ȥ���������ҲҪע����ôд
        midNode->next = nullptr;
        ListNode* list1 = head;
        while (list2) {
            ListNode* temp = list1->next;
            list1->next = list2;
            list1 = temp;
            temp = list2->next;
            list2->next = list1;
            list2 = temp;
        }
    }
    // ����ָ�����м�ڵ㣬��876��
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // ԭ�ط�ת�����ݹ鷨�����е���������206��
    ListNode* reverseList(ListNode* head) { // head�����п���Ϊnullptr�ģ�������ֻ��һ������ʱ��
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
int main() {
    vector<int> arr{1, 2, 3, 4, 5};
    ListNode* head = new ListNode(arr[0]);
    ListNode* headTemp = head;
    for (int i = 1; i < arr.size(); i++) {
        headTemp->next = new ListNode(arr[i]);
        headTemp = headTemp->next;
    }
    Solution sol;
    headTemp = head;
    while (headTemp) {
        cout << headTemp->val << ' ';
        headTemp = headTemp->next;
    }
    cout << "\n";
    sol.reorderList(head);
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    system("pause");
    return 0;
}