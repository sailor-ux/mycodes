#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << "\n";
}

int main() {
    int n, m, num;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        while (n--) {
            cin >> m;
            if (m == 0) {
                cout << "这一行没有数据！" << endl;
                continue;
            }
            ListNode* dummyHead = new ListNode(-1);
            ListNode* node = dummyHead;
            while (m--) {
                cin >> num;
                node->next = new ListNode(num);
                node = node->next;
            }
            printList(dummyHead->next);
            printList(reverseList(dummyHead->next));
        }
    }
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << "sizeof(long long) = " << sizeof(long long) << endl;
    system("pause");
    return 0;
}