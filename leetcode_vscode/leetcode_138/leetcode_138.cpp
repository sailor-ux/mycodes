#include <iostream>
#include <unordered_map>
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
        if (head == nullptr) {
            return head;
        }
        unordered_map<Node*, Node*> hash;
        Node* temp = head;
        while (temp) {
            hash[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp) {
            hash[temp]->next = temp->next == NULL ? NULL : hash[temp->next];
            hash[temp]->random = temp->random == NULL ? NULL : hash[temp->random];
            temp = temp->next;
        }
        return hash[head];
    }
};
int main() {

    system("pause");
    return 0;
}