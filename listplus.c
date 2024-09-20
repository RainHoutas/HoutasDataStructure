#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct ListNode {
    int val;
    struct ListNode *next;
};

// 合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    // 创建一个哑节点作为结果链表的头部
    struct ListNode dummy;
    struct ListNode *tail = &dummy;
    dummy.next = NULL;

    // 遍历两个链表
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else if (l1->val > l2->val) {
            tail->next = l2;
            l2 = l2->next;
        } else {
            // 如果两个节点的值相等，只链接一个节点
            tail->next = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // 将剩余的链表链接到结果链表的末尾
    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    return dummy.next;
}

// 辅助函数：创建新节点
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// 辅助函数：打印链表
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // 创建第一个链表：1 -> 3 -> 5
    struct ListNode* l1 = newNode(1);
    l1->next = newNode(3);
    l1->next->next = newNode(5);

    // 创建第二个链表：2 -> 3 -> 4
    struct ListNode* l2 = newNode(2);
    l2->next = newNode(3);
    l2->next->next = newNode(4);

    // 合并链表
    struct ListNode* mergedList = mergeTwoLists(l1, l2);

    // 打印结果链表
    printList(mergedList);

    return 0;
}