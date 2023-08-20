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
    // ������
    // ����-��¡�������м䣻
    // ����-����¡����random��ֵ��
    // ����-��˿����(�����¾�����)----��ʹ��hash����ռ�ö���Ŀռ䣬�����˿ռ临�Ӷ�
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
        while (curNode) { // ��˿���ѣ����ѳ����������ǵ�Ҫ�ָ�ԭ����
            Node* cloneNode = curNode->next;
            Node* nextNode = cloneNode->next;
            curNode->next = nextNode; // �ָ�ԭ����
            cloneNode->next = nextNode ? nextNode->next : NULL;
            curNode = nextNode;
        }
        return newHead;
    }
    // ʹ��hash�洢ԭ���Ϳ�¡����ӳ���ϵ��ͨ��ӳ���ϵ�����¡����randomָ���nextָ��
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