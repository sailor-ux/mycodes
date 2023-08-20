#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //  思路：p2向后走k-1步，使得p2指向第k个，p1指向第1个
    //  当p2走到最后一个时，p2指向第n个，p1指向第n-k+1个，即倒数第k个
    //  实际：p2向后走k步，使得p2指向第k+1个，p1指向第1个
    //  当p2走到最后一个的下一个时，p2指向第n+1个, p2为NULL，p1指向第n-k+1个，即倒数第k个
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head || k == 0) {
            return NULL;
        }
        ListNode *p1 = head, *p2 = head;
        while (k--) {
            if (!p2) {
                return NULL;
            }
            p2 = p2->next;
        }
        while (p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
int main() {

    system("pause");
    return 0;
}