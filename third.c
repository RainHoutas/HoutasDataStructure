#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 判断单链表是否有序
int ListOrder_L(Node* head) {
    if (!head || !head->next) return 1; // 空链表或只有一个节点的链表视为有序

    int isNonDecreasing = 1, isNonIncreasing = 1;
    Node* current = head;

    while (current->next) {
        if (current->data > current->next->data) isNonDecreasing = 0;
        if (current->data < current->next->data) isNonIncreasing = 0;
        current = current->next;
    }

    return isNonDecreasing || isNonIncreasing;
}

// 对单链表进行非递减排序
void ListNonDesc_L(Node** head) {
    if (!(*head) || !(*head)->next) return; // 空链表或只有一个节点的链表无需排序

    Node* sorted = NULL;
    Node* current = *head;

    while (current) {
        Node* next = current->next;
        if (!sorted || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    *head = sorted;
}

// 逆转单链表
void ListReverse_L(Node** head) {
    if (!(*head) || !(*head)->next) return; // 空链表或只有一个节点的链表无需逆转

    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 打印链表
void printList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 测试函数
int main() {
    Node* head = createNode(3);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(4);

    printf("原链表: ");
    printList(head);

    printf("是否有序: %d\n", ListOrder_L(head));

    ListNonDesc_L(&head);
    printf("排序: ");
    printList(head);

    ListReverse_L(&head);
    printf("倒序: ");
    printList(head);

    return 0;
}