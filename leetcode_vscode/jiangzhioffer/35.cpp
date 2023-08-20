#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
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
    // 三部曲
    // 遍历-克隆结点插在中间；
    // 遍历-给克隆结点的random赋值；
    // 遍历-有丝分裂(分离新旧链表)----不使用hash表，不占用额外的空间，降低了空间复杂度
    Node* copyRandomList(Node* head) {
        if (!head) {
            return head;
        }
        Node* curNode = head;
        while (curNode) {
            Node* cloneNode = new Node(curNode->val);
            cloneNode->next = curNode->next;
            curNode->next = cloneNode;
            curNode = curNode->next->next;
            // curNode = cloneNode->next;
        }
        curNode = head;
        while (curNode) {
            curNode->next->random = curNode->random ? curNode->random->next : NULL;
            curNode = curNode->next->next;
        }
        curNode = head;
        Node* newHead = head->next;
        while (curNode) { // 有丝分裂，分裂成两个链表，记得要恢复原链表！
            Node* cloneNode = curNode->next;
            Node* nextNode = cloneNode->next;
            curNode->next = nextNode; // 恢复原链表
            cloneNode->next = nextNode ? nextNode->next : NULL;
            curNode = nextNode;
        }
        return newHead;
    }
    // 使用hash存储原结点和克隆结点的映射关系，通过映射关系处理克隆结点的random指针和next指针
    Node* copyRandomList(Node* head) {
        if (!head) {
            return head;
        }
        unordered_map<Node*, Node*> mp;
        Node* temp = head;
        while (temp) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp) {
            mp[temp]->next = temp->next ? mp[temp->next] : NULL;
            mp[temp]->random = temp->random ? mp[temp->random] : NULL;
            temp = temp->next;
        }
        return mp[head];
    }
};
int main() {

    system("pause");
    return 0;
}