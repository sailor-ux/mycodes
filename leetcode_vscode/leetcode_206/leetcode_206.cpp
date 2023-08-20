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
    ListNode* reverseList(ListNode* head) {
        // �ݹ鷨������⣬���Ǻܺ���⣡����
        // ȷ���ݹ麯��reverseList�Ķ��壡����
        if (!head || !head->next) { //��һ�����ǵ���headΪnull�ǿ������������ڶ������ǵݹ�ĳ��ڣ���Ӧ��С������
            return head;            // һ·����㣬���ػ�ȥ   ���if�ڵ�����if������������ƣ�˵����С�����⿼�ǵû�����С����������Сһ������
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
int main() {
    vector<int> vec{1, 2, 3, 4};
    ListNode* head = new ListNode();
    ListNode* node = head;
    for (int i = 0; i < vec.size(); i++) {
        node->val = vec[i];
        if (i < vec.size() - 1) {
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
    node = sol.reverseList(head);
    while (node) {
        cout << node->val << ' ';
        node = node->next;
    }
    system("pause");
    return 0;
}

// �ռ临�Ӷ�O(n)��û��ԭ�ط�ת������
// ListNode* ans = nullptr;
// for (ListNode* node = head; node != nullptr; node = node->next) {
//     ans = new ListNode(node->val, ans);
// }
// return ans;

// ������
// ListNode* prev = nullptr;
// ListNode* curr = head;
// while (curr) {
//     ListNode* temp = curr->next;
//     curr->next = prev;
//     prev = curr;
//     curr = temp;
// }
// return prev;