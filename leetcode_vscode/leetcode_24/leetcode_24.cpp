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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummyHead(-1, head);
        ListNode *prev = &dummyHead, *cur = head;
        while (cur && cur->next) {
            ListNode* nextNode = cur->next;
            cur->next = nextNode->next;
            nextNode->next = cur;
            prev->next = nextNode;
            prev = cur;
            cur = cur->next;
        }
        return dummyHead.next;
    }
};
int main() {
    vector<int> arr{1};
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
    head = sol.swapPairs(dummyHead->next);
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    system("pause");
    return 0;
}