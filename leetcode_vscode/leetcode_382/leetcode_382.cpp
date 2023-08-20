#include <iostream>
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
    ListNode* head;
    Solution(ListNode* head) : head(head) {
    }

    int getRandom() { //��ˮ�س����㷨��������������....
        int i = 1, ans;
        for (auto node = head; node; node = node->next) {
            if (rand() % i == 0) {
                ans = node->val;
            }
            ++i;
        }
        return ans;
    }
};
int main() {

    system("pause");
    return 0;
}