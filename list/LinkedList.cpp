#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
};
//在链表的节点n0之后插入节点P
void insert (ListNode* n0, ListNode *P) {
    ListNode *n1 = n0 -> next;
    P -> next = n1;
    n0 -> next = P;
}
//删除链表的节点n0之后的首个节点
void remove (ListNode* n0) {
    if (n0 -> next == nullptr)
        return;
    //n0 -> P -> n1
    ListNode *P = n0 -> next;
    ListNode *n1 = P ->next;
    n0 -> next = n1;

    delete P;
}
//访问链表中索引为index的节点
ListNode *access (ListNode *head, int index) {
    for (int i = 0; i < index; i++) {
        if (head == nullptr)
            return nullptr;
        head = head -> next;
    }
}
//在链表中查找第一个值为target的节点，并返回其索引
int find(ListNode *head, int target) {
    int index = 0;
    while (head != nullptr) {
        if (head -> val == target) {
            return index;
        }
        head = head -> next;
        index ++;
    }
    return -1;
}