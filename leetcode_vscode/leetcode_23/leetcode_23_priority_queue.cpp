#include <iostream>
#include <queue>
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
    struct Status {
        int val;
        ListNode* ptr;
        bool operator<(const Status& rhs) const {
            return val > rhs.val;
        }
    };
    priority_queue<Status> q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (ListNode* list : lists) {
            if (list) {
                q.push({list->val, list});
            }
        }
        ListNode dummyHead, *tail = &dummyHead;
        while (!q.empty()) {
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next) {
                q.push({f.ptr->next->val, f.ptr->next});
            }
        }
        return dummyHead.next;
    }
};
int main() {

    system("pause");
    return 0;
}