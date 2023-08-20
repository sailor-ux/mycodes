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
    // ��������������ĺϲ����֣���
    // ������������ĺϲ�����������µĽ�㣬�½���val=ԭ����val����ô�ռ临�ӶȽ��ﵽo(m+n)��������ռ临�Ӷ�o(1)����������ֻ���ǣ�ԭ���޸Ľ���nextָ�룡����
    /* ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if (!a || !b) {
            return a ? a : b;
        }
        ListNode* dummyHead = new ListNode();
        ListNode *aPtr = a, *bPtr = b, *tail = dummyHead;
        while (aPtr || bPtr) {
            if (!aPtr || !bPtr) {
                tail->next = aPtr != nullptr ? aPtr : bPtr;
                break;
            }
            tail->next = aPtr->val < bPtr->val ? aPtr : bPtr;
            tail = tail->next;
            tail == aPtr ? aPtr = aPtr->next : bPtr = bPtr->next;
        }
        return dummyHead->next;
    } */
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if (!a || !b) {
            return a ? a : b;
        }
        ListNode* dummyHead = new ListNode();
        ListNode *aPtr = a, *bPtr = b, *tail = dummyHead;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr;
                aPtr = aPtr->next;
            } else {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        /* if (aPtr) {
            tail->next = aPtr;
        }
        if (bPtr) {
            tail->next = bPtr;
        } */
        tail->next = aPtr ? aPtr : bPtr;
        return dummyHead->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;
        for (int i = 0; i < lists.size(); i++) {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
    // ������˳��ϲ�
    // �����Ƿ��κϲ���Ҳ�ǻ���������������ĺϲ�����
    /* ListNode* merge(const vector<ListNode*>& lists, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        if (l == r) {
            return lists[l];
        }
        return mergeTwoLists(lists[l], merge(lists, l + 1, r));//�ֵĲ��ã�
    } */
    // �����ķ����㷨���죡���������룡
    ListNode* merge(const vector<ListNode*>& lists, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        if (l == r) {
            return lists[l];
        }
        int mid = (l + r) / 2;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};
int main() {

    system("pause");
    return 0;
}