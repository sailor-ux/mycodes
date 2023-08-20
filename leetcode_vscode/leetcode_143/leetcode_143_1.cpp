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
    // 题解1，该方法空间复杂度O(n)，意义不大！
    void reorderList(ListNode* head) {
        vector<ListNode*> vec; // O(n)
        ListNode* node = head;
        while (node) {
            vec.push_back(node);
            node = node->next;
        }
        int i = 0, j = vec.size() - 1;
        while (j - i >= 2) {
            vec[j]->next = vec[i]->next;
            vec[i]->next = vec[j];
            i++;
            j--;
        }
        vec[j]->next = nullptr;
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