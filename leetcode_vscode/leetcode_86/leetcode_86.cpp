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
    ListNode* partition(ListNode* head, int x) {
        ListNode *small = nullptr, *smallHead = nullptr;
        ListNode *large = nullptr, *largeHead = nullptr;
        while (head) {
            if (head->val < x) {
                if (!small) {
                    small = head;
                    smallHead = head;
                    head = head->next;
                    continue;
                }
                small->next = head;
                small = small->next;
            } else {
                if (!large) {
                    large = head;
                    largeHead = head;
                    head = head->next;
                    continue;
                }
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        if (!small && !large) {
            return nullptr;
        } else if (!small) {
            large->next = nullptr;
            return largeHead;
        } else if (!large) {
            small->next = nullptr;
            return smallHead;
        } else { // else可以不套
            small->next = largeHead;
            large->next = nullptr;
            return smallHead;
        }
    }
};
int main() {
    vector<int> vec = {1, 4, 3, 2, 5, 2};
    ListNode* head = new ListNode();
    ListNode* temp = head;
    for (int i = 0; i < vec.size(); i++) {
        temp->val = vec[i];
        if (i < vec.size() - 1) {
            temp->next = new ListNode();
            temp = temp->next;
        }
    }
    Solution sol;
    head = sol.partition(head, 1);
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    // system("pause");
    return 0;
}

// 上述方法没有采用虚拟头节点，哑节点，处理起来十分麻烦！！！
// ListNode* smallHead = new ListNode(); //虚拟头节点，哑节点
// ListNode* largeHead = new ListNode(); //虚拟头节点，哑节点
// ListNode* small = smallHead;
// ListNode* large = largeHead;
// while (head) {
//     if (head->val < x) {
//         small->next = head;
//         small = small->next;
//     } else {
//         large->next = head;
//         large = large->next;
//     }
//     head = head->next;
// }
// small->next = largeHead->next;
// large->next = nullptr;
// return smallHead->next;