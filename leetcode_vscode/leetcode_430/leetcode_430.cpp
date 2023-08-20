#include <iostream>
#include <stack>
using namespace std;
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    //�Լ�д�ģ��Ƚ���������
    Node* flatten(Node* head) {
        stack<Node*> stk;
        Node* node = head;
        while (node) {
            while (node && node->child == nullptr) {
                node = node->next;
            }
            if (node) {
                stk.push(node);
                node = node->child;
            }
        }
        while (!stk.empty()) {
            Node* curr = stk.top();
            stk.pop();
            Node* lastNode = curr->child;
            while (lastNode->next) {
                lastNode = lastNode->next;
            }
            if (curr->next) {
                curr->next->prev = lastNode;
                lastNode->next = curr->next;
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            } else {
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }
        }
        return head;
    }
    //�ݹ飬�죡��ʵû�У�ʱ�䲻������
    Node* flatten(Node* head) {
        if (!head) {
            return head;
        }
        Node* dummyNode = new Node;
        dummyNode->next = head;
        while (head && head->child == nullptr) {
            head = head->next;
        }
        if (head) {
            Node* temp = head->next;
            head->next = flatten(head->child);
            head->next->prev = head;
            head->child = nullptr;
            if (temp) {
                while (head->next) {
                    head = head->next;
                }
                temp->prev = head;
                head->next = temp;
            }
        }
        return dummyNode->next;
    }
    /* ��������˼·����Ȼͨ���ˣ���ʵ��̫�ԣ���
    head�ǵ�һ�����ӽ��Ľ�㣬����������Ĭ���˺���Ľ���û���ӽ��
    ʵ����head�����temp����Լ��ٺ���Ľ�㶼���п��ܴ����ӽ��ģ����� */
    //�ݹ飬��ֿ�����head֮��Ľ��Ҳ�п������ӽ�㣡
    Node* flatten(Node* head) {
        if (!head) {
            return head;
        }
        Node* dummyNode = new Node;
        dummyNode->next = head;
        while (head) {
            while (head && head->child == nullptr) {
                head = head->next;
            }
            if (head) {
                Node* temp = head->next;
                head->next = flatten(head->child);
                head->next->prev = head;
                head->child = nullptr;
                if (temp) {
                    while (head->next) { // head�ߵ���β��㡱����������Ż�
                        head = head->next;
                    }
                    temp->prev = head;
                    head->next = temp;
                }
                head = temp;
            }
        }
        return dummyNode->next;
    }
    //�ݹ��Ż���������Ǿ���....
    Node* flatten(Node* head) { //��ƽ�������ر�ƽ�����ͷ���
        if (!head) {
            return head;
        }
        dfs(head);
        return head;
    }
    Node* dfs(Node* head) { //��ƽ�������ر�ƽ����ġ�β��㡱
        Node* last = head;
        while (head) {
            while (head && head->child == nullptr) {
                last = head; // last = last->next�����ԣ�����֤last��ǰ��head�ں󣬴�д�����Լ���������������
                head = head->next;
            }
            if (head) {
                Node* temp = head->next;
                Node* lastNode = dfs(head->child); //��β��㡱, һ���ǿգ�
                head->next = head->child;
                head->child->prev = head;
                head->child = nullptr;
                last = lastNode;
                if (temp) {
                    temp->prev = lastNode;
                    lastNode->next = temp;
                }
                head = temp;
            }
        }
        return last;
    }
    //
    Node* flatten(Node* head) { //��ƽ�������ر�ƽ�����ͷ���
        if (!head) {
            return head;
        }
        dfs(head);
        return head;
    }
    Node* dfs(Node* head) { //��ƽ�������ر�ƽ����ġ�β��㡱
        Node* last = head;
        while (head) {
            if (head->child == nullptr) {
                last = head; // last = last->next�����ԣ�����֤last��ǰ��head�ں󣬴�д�����Լ���������������
                head = head->next;
            } else {
                Node* temp = head->next;
                Node* lastNode = dfs(head->child); //��β��㡱, һ���ǿգ�
                head->next = head->child;
                head->child->prev = head;
                head->child = nullptr;
                last = lastNode;
                if (temp) {
                    temp->prev = lastNode;
                    lastNode->next = temp;
                }
                head = temp;
            }
        }
        return last;
    }
};
int main() {

    system("pause");
    return 0;
}