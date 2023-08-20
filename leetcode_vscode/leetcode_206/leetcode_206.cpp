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
        // 递归法，多理解，不是很好理解！！！
        // 确定递归函数reverseList的定义！！！
        if (!head || !head->next) { //第一个考虑的是head为null是空链表的情况，第二个才是递归的出口，对应最小子问题
            return head;            // 一路向外层，返回回去   如果if内的语句跟if后面的语句很相似，说明最小子问题考虑得还不够小，还可以再小一步！！
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

// 空间复杂度O(n)，没有原地反转！！！
// ListNode* ans = nullptr;
// for (ListNode* node = head; node != nullptr; node = node->next) {
//     ans = new ListNode(node->val, ans);
// }
// return ans;

// 迭代法
// ListNode* prev = nullptr;
// ListNode* curr = head;
// while (curr) {
//     ListNode* temp = curr->next;
//     curr->next = prev;
//     prev = curr;
//     curr = temp;
// }
// return prev;