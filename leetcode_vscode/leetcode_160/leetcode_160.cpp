#include <iostream>
#include <unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> st;
        while (headA) {
            st.insert(headA);
            headA = headA->next;
        }
        while (headB && st.find(headB) == st.end()) {
            headB = headB->next;
        }
        return headB;
    }
};
int main() {

    system("pause");
    return 0;
}