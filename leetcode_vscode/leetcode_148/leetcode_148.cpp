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
    // ʱ��ռ临�Ӷȶ���O(2*n)
    // ��Ҫ����O(n*logn)  O(1)
    ListNode* sortList(ListNode* head) {
        if (!head) {
            return head;
        }
        vector<pair<int, ListNode*>> table; // ������unordered_map��map�������������ܽ�����sort����
        while (head) {
            table.push_back(make_pair(head->val, head));
            head = head->next;
        }
        sort(table.begin(), table.end()); // ע������������򣡣���
        for (int i = 0; i < table.size(); i++) {
            if (i == table.size() - 1) {
                table[i].second->next = nullptr;
                break;
            }
            table[i].second->next = table[i + 1].second;
        }
        return table[0].second;
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