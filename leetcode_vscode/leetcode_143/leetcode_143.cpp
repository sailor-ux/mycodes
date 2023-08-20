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
    // 自己写的效率太低，还要去看题解！！！
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        int sum = 0;
        while (temp) {
            sum++;
            temp = temp->next;
        }
        int times = sum % 2 == 0 ? sum / 2 - 1 : sum / 2;
        temp = head;
        for (int i = 1; i <= sum - times - 1; i++) {
            temp = temp->next;
        }
        ListNode* headTemp = head;
        while (times) {
            ListNode* tempTemp = temp;
            for (int i = 1; i <= times; i++) {
                tempTemp = tempTemp->next;
            }
            tempTemp->next = headTemp->next;
            headTemp->next = tempTemp;
            headTemp = tempTemp->next;
            times--;
        }
        temp->next = nullptr;
    }
};
int main() {
    vector<int> arr{1, 2, 3, 4};
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