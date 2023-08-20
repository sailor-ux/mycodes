#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return head;
        }
        Node* curNode = head;
        while (curNode) {
            Node* nextNode = curNode->next;
            curNode->next = new Node(curNode->val);
            curNode->next->next = nextNode;
            curNode = nextNode;
        }
        curNode = head;
        while (curNode) {
            Node* copyNode = curNode->next;
            Node* nextNode = copyNode->next;
            copyNode->random = curNode->random == NULL ? NULL : curNode->random->next;
            curNode = nextNode;
        }
        curNode = head;
        Node* newHead = head->next;
        while (curNode) {
            Node* copyNode = curNode->next;
            Node* nextNode = copyNode->next;
            curNode->next = nextNode;
            copyNode->next = nextNode == NULL ? NULL : nextNode->next;
            curNode = nextNode;
        }
        return newHead;
    }
};
int main() {

    system("pause");
    return 0;
}