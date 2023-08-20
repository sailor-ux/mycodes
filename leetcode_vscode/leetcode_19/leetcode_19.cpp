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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummyHead(-1, head);
        ListNode* prev = &dummyHead;
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        count -= n;
        while (count) {
            prev = prev->next;
            count--;
        }
        prev->next = prev->next->next;
        return dummyHead.next;
    }
    // prev->next = prev->next->next
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
    head = sol.removeNthFromEnd(dummyHead->next, 6);
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    system("pause");
    return 0;
}