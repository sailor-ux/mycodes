#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //  ˼·��p2�����k-1����ʹ��p2ָ���k����p1ָ���1��
    //  ��p2�ߵ����һ��ʱ��p2ָ���n����p1ָ���n-k+1������������k��
    //  ʵ�ʣ�p2�����k����ʹ��p2ָ���k+1����p1ָ���1��
    //  ��p2�ߵ����һ������һ��ʱ��p2ָ���n+1��, p2ΪNULL��p1ָ���n-k+1������������k��
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