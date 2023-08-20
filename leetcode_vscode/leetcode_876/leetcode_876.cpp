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
    ListNode* middleNode(ListNode* head) {
        // ��1���ռ临�Ӷ�O(n)
        // vector<ListNode*> vec; O(n)
        // while (head) {
        //     vec.push_back(head);
        //     head = head->next;
        // }
        // return vec[vec.size() / 2];

        // ��2����ָ�뷨���ռ临�Ӷ�O(1)
        // ListNode* node = head;
        // int sum = 0;
        // while (node) {
        //     sum++;
        //     node = node->next;
        // }
        // sum = sum / 2 + 1;
        // while (sum-- > 1) {
        //     head = head->next;
        //     // sum--;
        // }
        // return head;

        // ����ָ�뷨��Ѱ���м���(��һ��ż����ʱ���ҵ��м�ƫ��)
        // Ҫȥ��ϰ206��ԭ�ط�ת����
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
    cout << sol.middleNode(head)->val;
    system("pause");
    return 0;
}