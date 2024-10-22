#include <stdio.h>
#include <stdlib.h>

// ���嵥����ڵ�ṹ
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// �жϵ������Ƿ�����
int ListOrder_L(Node* head) {
    if (!head || !head->next) return 1; // �������ֻ��һ���ڵ��������Ϊ����

    int isNonDecreasing = 1, isNonIncreasing = 1;
    Node* current = head;

    while (current->next) {
        if (current->data > current->next->data) isNonDecreasing = 0;
        if (current->data < current->next->data) isNonIncreasing = 0;
        current = current->next;
    }

    return isNonDecreasing || isNonIncreasing;
}

// �Ե�������зǵݼ�����
void ListNonDesc_L(Node** head) {
    if (!(*head) || !(*head)->next) return; // �������ֻ��һ���ڵ��������������

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

// ��ת������
void ListReverse_L(Node** head) {
    if (!(*head) || !(*head)->next) return; // �������ֻ��һ���ڵ������������ת

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

// �����½ڵ�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ��ӡ����
void printList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// ���Ժ���
int main() {
    Node* head = createNode(3);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(4);

    printf("ԭ����: ");
    printList(head);

    printf("�Ƿ�����: %d\n", ListOrder_L(head));

    ListNonDesc_L(&head);
    printf("����: ");
    printList(head);

    ListReverse_L(&head);
    printf("����: ");
    printList(head);

    return 0;
}