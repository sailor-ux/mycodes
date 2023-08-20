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
    //自己写的，比较慢！！！
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
    //递归，快！其实没有，时间不定！！
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
    /* 以上两个思路，虽然通过了，其实不太对！！
    head是第一个有子结点的结点，这两个方法默认了后面的结点就没有子结点
    实际上head后面的temp结点以及再后面的结点都是有可能存在子结点的！！！ */
    //递归，充分考虑了head之后的结点也有可能有子结点！
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
                    while (head->next) { // head走到“尾结点”，这里可以优化
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
    //递归优化，结果还是巨慢....
    Node* flatten(Node* head) { //扁平化，返回扁平化后的头结点
        if (!head) {
            return head;
        }
        dfs(head);
        return head;
    }
    Node* dfs(Node* head) { //扁平化，返回扁平化后的“尾结点”
        Node* last = head;
        while (head) {
            while (head && head->child == nullptr) {
                last = head; // last = last->next不可以！！保证last在前，head在后，此写法可以兼顾两种情况！！！
                head = head->next;
            }
            if (head) {
                Node* temp = head->next;
                Node* lastNode = dfs(head->child); //“尾结点”, 一定非空！
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
    Node* flatten(Node* head) { //扁平化，返回扁平化后的头结点
        if (!head) {
            return head;
        }
        dfs(head);
        return head;
    }
    Node* dfs(Node* head) { //扁平化，返回扁平化后的“尾结点”
        Node* last = head;
        while (head) {
            if (head->child == nullptr) {
                last = head; // last = last->next不可以！！保证last在前，head在后，此写法可以兼顾两种情况！！！
                head = head->next;
            } else {
                Node* temp = head->next;
                Node* lastNode = dfs(head->child); //“尾结点”, 一定非空！
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