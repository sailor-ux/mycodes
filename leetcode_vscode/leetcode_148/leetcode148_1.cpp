#include <algorithm>
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
    // �Զ����µĵݹ飬�鲢����(�ʺ����������ԭ�����������ֳ�ǰ�������֣��ֱ������ںͲ�������˼��)
    // �ݹ����ջ�ռ䣬���Կռ临�Ӷ�ΪO(logn)
    ListNode* sortList(ListNode* head) {
        if (!head) {
            return head;
        }
        return sortList(head, nullptr);
    }
    ListNode* sortList(ListNode* head, ListNode* tail) { // [head, tail)���ݹ麯���Ķ���
        if (head->next == tail) {                        // �ݹ�ĳ��ڣ���Ӧ��С������<--->ֻ��һ���������
            head->next = nullptr;
            return head;
        }
        ListNode *fast = head, *slow = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode* midNode = slow;
        return merge(sortList(head, midNode), sortList(midNode, tail));
    }
    // ��20+�⣬�ϲ�������������
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode();
        ListNode* temp = dummyHead;
        ListNode *temp1 = head1, *temp2 = head2;
        while (temp1 || temp2) {
            if (!temp1) {
                temp->next = temp2;
                break;
            }
            if (!temp2) {
                temp->next = temp1;
                break;
            }
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        return dummyHead->next;
    }
};
int main() {
    vector<int> arr{4, 2, 1, 3};
    ListNode* head = new ListNode();
    ListNode* node = head;
    for (int i = 0; i < arr.size(); i++) {
        node->val = arr[i];
        if (i < arr.size() - 1) {
            node->next = new ListNode();
        }
        node = node->next;
    }
    node = head;
    while (node) {
        cout << node->val << ' ';
        node = node->next;
    }
    cout << "\n";
    Solution sol;
    node = sol.sortList(head);
    while (node) {
        cout << node->val << ' ';
        node = node->next;
    }
    system("pause");
    return 0;
}